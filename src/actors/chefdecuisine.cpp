#include "ChefDeCuisine.h"
#include "../utils/Timer.h"
#include "../utils/Logger.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <chrono>
#include <mutex>

// Mutex global pour synchroniser les accès à la base de données
extern std::mutex dbMutex;

// Mutex global pour l'affichage
extern std::mutex affichageMutex;

ChefDeCuisine::ChefDeCuisine()
    : dbManager(DatabaseManager::instance()), actif(false), prochainChef(0) {
    // Initialiser 2 chefs de partie
    for (int i = 0; i < 2; ++i) {
        ChefDePartie* chef = new ChefDePartie(i + 1);
        chefsDePartie.push_back(chef);
        chef->start(); // Démarrer immédiatement les threads des chefs de partie
    }
    Logger::instance().log("Chef de Cuisine initialisé avec 2 chefs de partie.");
}

ChefDeCuisine::~ChefDeCuisine() {
    stop();
    for (ChefDePartie* chef : chefsDePartie) {
        chef->stop();
        delete chef;
    }
    Logger::instance().log("Chef de Cuisine et chefs de partie arrêtés.");
}

void ChefDeCuisine::start() {
    actif = true;
    threadCuisine = std::thread(&ChefDeCuisine::cycleDeTravail, this);
    Logger::instance().log("Cycle de travail du Chef de Cuisine démarré.");
}

void ChefDeCuisine::stop() {
    actif = false;
    if (threadCuisine.joinable()) {
        threadCuisine.join();
    }
    Logger::instance().log("Cycle de travail du Chef de Cuisine arrêté.");
}

void ChefDeCuisine::cycleDeTravail() {
    while (actif) {
        Timer& timer = Timer::instance();

        if (!timer.isRestaurantOpen()) {
            Logger::instance().log("Restaurant fermé. Arrêt des activités.");
            std::this_thread::sleep_for(std::chrono::hours(1)); // Attente jusqu'à 10h
            continue;
        }

        if ((timer.isDayShift() && !isDayTeamActive) || (timer.isNightShift() && isDayTeamActive)) {
            handleShiftChange(); // Gérer le changement d'équipe
        }

        gererCommandes();
        distribuerTaches();
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Attente simulée
    }
}

void ChefDeCuisine::handleShiftChange() {
    Logger::instance().log("Début du changement d'équipe.");
    isDayTeamActive = !isDayTeamActive;

    for (ChefDePartie* chef : chefsDePartie) {
        chef->stop(); // Arrêter les threads actuels
    }

    // Attendre quelques secondes pour simuler la transition
    std::this_thread::sleep_for(std::chrono::seconds(5));

    for (ChefDePartie* chef : chefsDePartie) {
        chef->start(); // Redémarrer avec la nouvelle équipe
    }

    Logger::instance().log("Changement d'équipe terminé.");
}

void ChefDeCuisine::gererCommandes() {
    std::lock_guard<std::mutex> lock(dbMutex); // Synchronisation des accès à la base de données

    QSqlQuery query(dbManager.getDatabase());

    // Récupérer les commandes en attente non assignées
    if (!query.exec("SELECT task_id, recipe_id FROM tasks WHERE status = 'En attente' AND assigned = 0 ORDER BY task_id")) {
        qCritical() << "Erreur lors de la récupération des commandes en attente :" << query.lastError().text();
        return;
    }

    QSqlQuery updateQueueQuery(dbManager.getDatabase());
    int position = 1;

    while (query.next()) {
        int taskId = query.value("task_id").toInt();
        int recipeId = query.value("recipe_id").toInt();

        if (ingredientsDisponibles(recipeId)) {
            mettreAJourStocks(recipeId);

            // Ajouter la tâche dans la file task_queue
            updateQueueQuery.prepare("INSERT INTO task_queue (task_id, queue_position) VALUES (:task_id, :queue_position)");
            updateQueueQuery.bindValue(":task_id", taskId);
            updateQueueQuery.bindValue(":queue_position", position++);
            if (!updateQueueQuery.exec()) {
                qCritical() << "Erreur lors de la mise à jour de task_queue :" << updateQueueQuery.lastError().text();
            }

            // Mettre à jour le statut en "En cours"
            QSqlQuery updateTaskQuery(dbManager.getDatabase());
            updateTaskQuery.prepare("UPDATE tasks SET status = 'En cours' WHERE task_id = :task_id");
            updateTaskQuery.bindValue(":task_id", taskId);
            if (!updateTaskQuery.exec()) {
                qCritical() << "Erreur lors de la mise à jour de l'état de la tâche :" << updateTaskQuery.lastError().text();
            } else {
                Logger::instance().log("Tâche ID " + std::to_string(taskId) + " mise en cours.");
            }
        } else {
            // Annuler la tâche si les ingrédients sont insuffisants
            QSqlQuery cancelQuery(dbManager.getDatabase());
            cancelQuery.prepare("UPDATE tasks SET status = 'Annulé' WHERE task_id = :task_id");
            cancelQuery.bindValue(":task_id", taskId);
            if (!cancelQuery.exec()) {
                qCritical() << "Erreur lors de l'annulation de la tâche :" << cancelQuery.lastError().text();
            } else {
                Logger::instance().log("Tâche ID " + std::to_string(taskId) + " annulée (ingrédients insuffisants).");
            }
        }
    }

    afficherOrdreDeTraitement();
}

void ChefDeCuisine::distribuerTaches() {
    std::lock_guard<std::mutex> lock(dbMutex); // Synchronisation des accès à la base de données

    QSqlQuery query(dbManager.getDatabase());

    // Récupérer les tâches en cours dans task_queue
    if (!query.exec("SELECT tq.task_id, t.recipe_id FROM task_queue tq JOIN tasks t ON tq.task_id = t.task_id WHERE t.assigned = 0 AND t.status = 'En cours' ORDER BY tq.queue_position")) {
        qCritical() << "Erreur lors de la récupération des tâches dans task_queue :" << query.lastError().text();
        return;
    }

    while (query.next()) {
        int recipeId = query.value("recipe_id").toInt();
        int taskId = query.value("task_id").toInt();

        // Distribuer la tâche à un chef de partie disponible
        for (int i = 0; i < chefsDePartie.size(); ++i) {
            int chefIndex = (prochainChef++) % static_cast<int>(chefsDePartie.size());
            ChefDePartie* chef = chefsDePartie[chefIndex];

            if (chef->peutPrendreTache()) {
                chef->ajouterTache(recipeId);

                // Mettre à jour la tâche comme assignée
                QSqlQuery assignQuery(dbManager.getDatabase());
                assignQuery.prepare("UPDATE tasks SET assigned = 1 WHERE task_id = :task_id");
                assignQuery.bindValue(":task_id", taskId);
                if (!assignQuery.exec()) {
                    qCritical() << "Erreur lors de la mise à jour du statut :" << assignQuery.lastError().text();
                } else {
                    Logger::instance().log("Tâche ID " + std::to_string(taskId) + " assignée au Chef de Partie " + std::to_string(chefIndex + 1));
                }
                break;
            }
        }
    }

    afficherRedistribution();
}

bool ChefDeCuisine::ingredientsDisponibles(int recipeId) {
    std::lock_guard<std::mutex> lock(dbMutex); // Synchronisation des accès à la base de données

    QSqlQuery query(dbManager.getDatabase());

    query.prepare(
        "SELECT ri.ingredient_id, ri.quantity_needed, i.stock_quantity "
        "FROM recipe_ingredients ri "
        "JOIN ingredients i ON ri.ingredient_id = i.ingredient_id "
        "WHERE ri.recipe_id = :recipe_id");
    query.bindValue(":recipe_id", recipeId);

    if (!query.exec()) {
        qCritical() << "Erreur lors de la vérification des ingrédients :" << query.lastError().text();
        return false;
    }

    while (query.next()) {
        int stock = query.value("stock_quantity").toInt();
        int needed = query.value("quantity_needed").toInt();

        if (stock < needed) {
            qDebug() << "Ingrédient insuffisant pour l'ID" << query.value("ingredient_id").toInt();
            return false;
        }
    }

    return true;
}

void ChefDeCuisine::mettreAJourStocks(int recipeId) {
    std::lock_guard<std::mutex> lock(dbMutex); // Synchronisation des accès à la base de données

    QSqlQuery query(dbManager.getDatabase());

    query.prepare(
        "UPDATE ingredients "
        "SET stock_quantity = stock_quantity - ("
        "  SELECT ri.quantity_needed "
        "  FROM recipe_ingredients ri "
        "  WHERE ri.recipe_id = :recipe_id AND ri.ingredient_id = ingredients.ingredient_id "
        ") "
        "WHERE EXISTS ("
        "  SELECT 1 "
        "  FROM recipe_ingredients ri "
        "  WHERE ri.recipe_id = :recipe_id AND ri.ingredient_id = ingredients.ingredient_id "
        ")");
    query.bindValue(":recipe_id", recipeId);

    if (!query.exec()) {
        qCritical() << "Erreur lors de la mise à jour des stocks :" << query.lastError().text();
    } else {
        Logger::instance().log("Stocks mis à jour pour la recette " + std::to_string(recipeId));
    }
}

void ChefDeCuisine::afficherOrdreDeTraitement() {
    std::lock_guard<std::mutex> lock(affichageMutex);
    qDebug() << "Ordre de traitement des recettes (FIFO) :";

    QSqlQuery query(dbManager.getDatabase());
    if (query.exec("SELECT tq.queue_position, t.recipe_id "
                   "FROM task_queue tq JOIN tasks t ON tq.task_id = t.task_id "
                   "ORDER BY tq.queue_position")) {
        while (query.next()) {
            qDebug() << "Position :" << query.value("queue_position").toInt()
            << "| Recette ID :" << query.value("recipe_id").toInt();
        }
    } else {
        qCritical() << "Erreur lors de l'affichage de l'ordre des traitements :" << query.lastError().text();
    }
}

void ChefDeCuisine::afficherRedistribution() {
    std::lock_guard<std::mutex> lock(affichageMutex);
    for (ChefDePartie* chef : chefsDePartie) {
        chef->afficherTaches();
    }
}
