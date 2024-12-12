#ifndef PLONGEUR_H
#define PLONGEUR_H

#include "../utils/Logger.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <queue>
#include <condition_variable>

class Plongeur {
public:
    explicit Plongeur();
    ~Plongeur();

    void start();                 // Démarrer le thread
    void stop();                  // Arrêter le thread
    void ajouterUstensile(int ustensileId); // Ajouter un ustensile à nettoyer

private:
    std::atomic<bool> actif;       // Indique si le plongeur est actif
    std::thread threadPlongeur;    // Thread du plongeur
    std::queue<int> ustensiles;    // File des ustensiles à nettoyer
    std::mutex mutexUstensiles;    // Mutex pour protéger l'accès à la file
    std::condition_variable condition;

    void nettoyerUstensiles();     // Nettoyer les ustensiles
};

#endif // PLONGEUR_H
