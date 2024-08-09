#pragma once
#include <string>
#include <fstream>

using namespace std;

class Logger {
private:
    static Logger* instance;
    ofstream logFile;

    Logger();
public:
    static Logger* getInstance();
    void log(const string& message);
    ~Logger();
};
