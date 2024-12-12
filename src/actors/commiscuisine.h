#ifndef COMMISCUISINE_H
#define COMMISCUISINE_H

#include "../database/DatabaseManager.h"
#include "../utils/Logger.h"
#include <thread>
#include <mutex>
#include <atomic>
#include <queue>
#include <string>
#include <condition_variable>

class CommisCuisine {
public:
    explicit CommisCuisine(int id);
    ~CommisCuisine();

    void start();                      // Démarrer le thread
    void stop();                       // Arrêter le thread
    void ajouterTache(const std::string& tache, int recetteId); // Ajouter une tâche
    void traiterTache();               // Cycle principal pour traiter les tâches
    void notifierUstensileDisponible(int ustensileId); // Notification d'ustensile disponible

private:
    int id;                            // ID du commis
    std::queue<std::pair<std::string, int>> taches; // File des tâches (description + recetteId)
    std::thread threadCommis;          // Thread du commis
    std::atomic<bool> actif;           // Indique si le commis est actif
    std::mutex mutexTaches;            // Mutex pour protéger l'accès à la file des tâches
    std::condition_variable condition; // Condition pour synchroniser le travail

    bool verifierDisponibiliteUstensile(int ustensileId);    // Vérifier la disponibilité d'un ustensile
    bool verifierDisponibiliteEquipement(int equipementId); // Vérifier la disponibilité d'un équipement
    void traiterEtape(int recetteId, const std::string& etape); // Traiter une étape spécifique d'une recette
};

#endif // COMMISCUISINE_H
