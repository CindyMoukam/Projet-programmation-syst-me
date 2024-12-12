#include "ChefDePartie.h"
#include "../database/DatabaseManager.h"
#include "../utils/Logger.h"
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>
#include <chrono>
#include <thread>

extern std::mutex dbMutex; // Mutex global pour synchronisation avec la base

ChefDePartie::ChefDePartie(int id)
    : id(id), actif(false), commis(new CommisCuisine(id)) {}

ChefDePartie::~ChefDePartie() {
    stop();
    delete commis; // Libérer la mémoire du commis
}

void ChefDePartie::start() {
    if (actif) return; // Éviter de démarrer plusieurs fois
    actif = true;
    commis->start(); // Démarrer le thread du commis
    threadTaches = std::thread(&ChefDePartie::cycleDeTravail, this);
    Logger::instance().log("Chef de Partie " + std::to_string(id) + " démarré.");
}

void ChefDePartie::stop() {
    actif = false;
    commis->stop(); // Arrêter le thread du commis
    if (threadTaches.joinable()) {
        threadTaches.join(); // Attendre la fin du thread
    }
    Logger::instance().log("Chef de Partie " + std::to_string(id) + " arrêté.");
}

bool ChefDePartie::peutPrendreTache() const {
    std::lock_guard<std::mutex> lock(mutexTaches);
    return taches.size() < 5; // Limite de 5 tâches simultanées
}

void ChefDePartie::ajouterTache(int recipeId) {
    {
        std::lock_guard<std::mutex> lock(mutexTaches);
        taches.push(recipeId);
    }
    Logger::instance().log("Chef de Partie " + std::to_string(id) +
                           " a reçu une tâche pour la recette " + std::to_string(recipeId));
}

void ChefDePartie::afficherTaches() const {
    std::lock_guard<std::mutex> lock(mutexTaches);
    std::cout << "Chef de Partie " << id << " traite les tâches suivantes : ";
    std::queue<int> temp = taches; // Copier la file pour l'affichage
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

void ChefDePartie::cycleDeTravail() {
    while (actif) {
        int recipeId = -1;

        {
            std::lock_guard<std::mutex> lock(mutexTaches);
            if (!taches.empty()) {
                recipeId = taches.front();
                taches.pop();
            }
        }

        if (recipeId != -1) {
            assignerTacheCommis(recipeId);
        } else {
            // Si aucune tâche, attendre un peu avant de vérifier à nouveau
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
}

void ChefDePartie::assignerTacheCommis(int recipeId) {
    Logger::instance().log("Chef de Partie " + std::to_string(id) +
                           " assigne une tâche au Commis de Cuisine pour la recette " + std::to_string(recipeId));

    commis->ajouterTache("Étape de la recette", recipeId); // Ajout de la tâche au commis
    Logger::instance().log("Tâche assignée au Commis de Cuisine " + std::to_string(id));
}
