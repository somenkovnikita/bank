/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   21 Jan 2018
*/

#include "Logger.hpp"

void Logger::setFile(const std::string &filename) {
    logFile = std::ofstream(filename, std::ios_base::app);
}
