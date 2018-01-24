/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   20 Jan 2018
*/

#pragma once


#include "Endpoint.hpp"

class Server {
public:
    explicit Server(const Endpoint &endpoint);
    bool initialize();
    void run();

private:
    Endpoint endpoint;
    int socket;
};

