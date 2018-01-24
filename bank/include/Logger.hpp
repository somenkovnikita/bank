/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   21 Jan 2018
*/

#pragma once

#include <string>
#include <fstream>
#include <iostream>

class Logger {
public:

    enum Level {
        Debug = 0x00,
        Error = 0x10
    };

    static Logger& log() {
        static Logger loggerInstance;
        return loggerInstance;
    }

    template <typename T>
    Logger& operator<<(const T &message) {

        std::lock_guard<std::mutex> guard(mutex);

        struct tm * timeinfo;

        time_t rawtime;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );

        if (!logFile.is_open()) {
            std::cerr << "Setup correct log file!" << std::endl;
            return *this;
        }

        auto asctm = asctime(timeinfo);
        asctm[strlen(asctm) - 1] = '\0';

        logFile << "[" << asctm << "] " << std::string(message) << std::endl;

        return *this;
    }


    void setFile(const std::string &filename);

private:
    std::mutex mutex;
    std::ofstream logFile;

    Logger() = default;
    Logger(const Logger &) = delete;
    void operator=(const Logger &) = delete;
};

