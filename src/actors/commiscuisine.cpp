#include "CommisCuisine.h"
#include "../utils/Logger.h"
#include <chrono>
#include <thread>
#include <QSqlQuery>
#include <QSqlError>

extern std::mutex dbMutex; // Mutex global pour synchroniser la base de données

CommisCuisine::CommisCuisine(int id) : id(id), actif(false) {}

CommisCuisine::~CommisCuisine() {
    stop();
}

void CommisCuisine::start() {
    actif = true;
    threadCommis = std::thread(&CommisCuisine::traiterTache, this);
    Logger::instance().log("Commis de Cuisine " + std::to_string(id) + " démarré.");
}

void CommisCuisine::stop() {
    actif = false;
    if (threadCommis.joinable()) {
        threadCommis.join();
    }
    Logger::instance().log("Commis de Cuisine " + std::to_string(id) + " arrêté.");
}

void CommisCuisine::ajouterTache(const std::string& tache, int recetteId) {
    {
        std::lock_guard<std::mutex> lock(mutexTaches);
        taches.push({tache, recetteId});
    }
    condition.notify_one(); // Signaler qu'une nouvelle tâche est disponible
    Logger::instance().log("Commis de Cuisine " + std::to_string(id) +
                           " a reçu une tâche : " + tache + " pour la recette " +
                           std::to_string(recetteId));
}

void CommisCuisine::traiterTache() {
    while (actif) {
        std::unique_lock<std::mutex> lock(mutexTaches);
        condition.wait(lock, [this]() { return !taches.empty() || !actif; });

        if (!actif) break;

        auto tache = taches.front();
        taches.pop();
        lock.unlock();

        traiterEtape(tache.second, tache.first);
    }
}

void CommisCuisine::traiterEtape(int recetteId, const std::string& etape) {
    Logger::instance().log("Commis de Cuisine " + std::to_string(id) +
                           " commence l'étape : " + etape +
                           " pour la recette " + std::to_string(recetteId));

    // Vérifier disponibilité des ustensiles ou équipements nécessaires
    if (!verifierDisponibiliteUstensile(recetteId) || !verifierDisponibiliteEquipement(recetteId)) {
        Logger::instance().log("Commis de Cuisine " + std::to_string(id) +
                               " ne peut pas continuer l'étape " + etape +
                               " car des ressources sont indisponibles.");
        return;
    }

    // Simuler le temps de traitement de l'étape
    std::this_thread::sleep_for(std::chrono::seconds(2));

    Logger::instance().log("Commis de Cuisine " + std::to_string(id) +
                           " a terminé l'étape : " + etape +
                           " pour la recette " + std::to_string(recetteId));

    // Notifier disponibilité des ustensiles après utilisation
    notifierUstensileDisponible(recetteId);
}

void CommisCuisine::notifierUstensileDisponible(int ustensileId) {
    Logger::instance().log("Commis de Cuisine " + std::to_string(id) +
                           " signale que l'ustensile " + std::to_string(ustensileId) +
                           " est disponible pour nettoyage.");
}

bool CommisCuisine::verifierDisponibiliteUstensile(int ustensileId) {
    std::lock_guard<std::mutex> lock(dbMutex);

    QSqlQuery query(DatabaseManager::instance().getDatabase());
    query.prepare("SELECT status FROM ustensils WHERE ustensil_id = :ustensil_id");
    query.bindValue(":ustensil_id", ustensileId);

    if (!query.exec() || !query.next()) {
        Logger::instance().log("Erreur lors de la vérification de l'ustensile " +
                               std::to_string(ustensileId));
        return false;
    }

    std::string status = query.value("status").toString().toStdString();
    return status == "Disponible";
}

bool CommisCuisine::verifierDisponibiliteEquipement(int equipementId) {
    std::lock_guard<std::mutex> lock(dbMutex);

    QSqlQuery query(DatabaseManager::instance().getDatabase());
    query.prepare("SELECT status FROM equipment WHERE equipment_id = :equipment_id");
    query.bindValue(":equipment_id", equipementId);

    if (!query.exec() || !query.next()) {
        Logger::instance().log("Erreur lors de la vérification de l'équipement " +
                               std::to_string(equipementId));
        return false;
    }

    std::string status = query.value("status").toString().toStdString();
    return status == "Disponible";
}
