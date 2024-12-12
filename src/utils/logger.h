#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <mutex>

class Logger {
public:
    static Logger& instance();
    void log(const std::string& message);

private:
    Logger();
    ~Logger();
    std::ofstream logFile;
    std::mutex logMutex;
};

#endif // LOGGER_H
