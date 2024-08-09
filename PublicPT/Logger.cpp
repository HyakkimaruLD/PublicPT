#include "Logger.h"

Logger* Logger::instance = nullptr;

Logger::Logger() {
    logFile.open("task_log.txt", ios::app);
}

Logger* Logger::getInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

void Logger::log(const string& message) {
    logFile << message << endl;
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}
