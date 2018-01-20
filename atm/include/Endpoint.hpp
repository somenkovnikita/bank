/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   19 Jan 2018
*/

#pragma once

#include <string>
#include <fstream>

struct Endpoint {
    std::string ip;
    unsigned short port;

    bool readEndpoint(const std::string &filename);
};

