#include "Plongeur.h"
#include "../utils/Logger.h"
#include <chrono>
#include <thread>

Plongeur::Plongeur() : actif(false) {}

Plongeur::~Plongeur() {
    stop();
}

void Plongeur::start() {
    actif = true;
    threadPlongeur = std::thread(&Plongeur::nettoyerUstensiles, this);
    Logger::instance().log("Plongeur démarré.");
}

void Plongeur::stop() {
    actif = false;
    if (threadPlongeur.joinable()) {
        threadPlongeur.join();
    }
    Logger::instance().log("Plongeur arrêté.");
}

void Plongeur::ajouterUstensile(int ustensileId) {
    {
        std::lock_guard<std::mutex> lock(mutexUstensiles);
        ustensiles.push(ustensileId);
    }
    condition.notify_one(); // Notifier qu'un ustensile est disponible
    Logger::instance().log("Plongeur a reçu l'ustensile " +
                           std::to_string(ustensileId) + " pour nettoyage.");
}

void Plongeur::nettoyerUstensiles() {
    while (actif) {
        std::unique_lock<std::mutex> lock(mutexUstensiles);
        condition.wait(lock, [this]() { return !ustensiles.empty() || !actif; });

        if (!actif) break;

        int ustensileId = ustensiles.front();
        ustensiles.pop();
        lock.unlock();

        Logger::instance().log("Plongeur nettoie l'ustensile " +
                               std::to_string(ustensileId));

        // Simuler le temps de nettoyage
        std::this_thread::sleep_for(std::chrono::seconds(1));

        Logger::instance().log("Plongeur a terminé de nettoyer l'ustensile " +
                               std::to_string(ustensileId));
    }
}
