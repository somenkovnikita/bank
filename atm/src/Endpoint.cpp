/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   19 Jan 2018
*/

#include "Endpoint.hpp"

template <typename T>
bool _tryRead(T &t, std::ifstream &file) {
    if (file.eof()) return false;
    file >> t;
    return true;
}


bool Endpoint::readEndpoint(const std::string &filename) {
    std::ifstream file(filename);

    if (file.is_open()) return false;

    bool status = _tryRead(ip, file) || _tryRead(port, file);

    file.close();
    return status;
}
