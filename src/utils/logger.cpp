#include "Logger.h"
#include "Timer.h"
#include <iostream>

Logger::Logger() {
    logFile.open("restaurant_logs.txt", std::ios::app); // Ouvrir en mode ajout
    if (!logFile) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier de log." << std::endl;
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

Logger& Logger::instance() {
    static Logger instance;
    return instance;
}

void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex);

    // Obtenir l'heure simulée à partir du Timer
    Timer& timer = Timer::instance();
    std::string simulatedTime = timer.getCurrentTime();

    // Écrire dans le fichier log avec l'heure simulée
    if (logFile) {
        logFile << "[" << simulatedTime << "] " << message << std::endl;
    }
}
