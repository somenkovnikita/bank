/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   20 Jan 2018
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <Logger.hpp>

#include "Worker.hpp"
#include "Server.hpp"
#include "Connection.hpp"

Server::Server(const Endpoint &endpoint) : endpoint(endpoint) {
    Logger::log() << "Starting server...";
}

bool Server::initialize() {
    Logger::log() << "Server initialize...";
    
    if ((socket = ::socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        Logger::log() << "Socket create failed";
        return false;
    }
    int enable = 1;
    setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));

    sockaddr_in sock{};
    sock.sin_addr.s_addr = inet_addr(endpoint.ip.c_str());
    sock.sin_port = htons(endpoint.port);

    const sockaddr *s = reinterpret_cast<sockaddr *>(&sock);
    if (::bind(socket, s, sizeof(sock)) < 0) {
        Logger::log() << "Bind failed";
        return false;
    }
    Logger::log() << "Server initialized";

    return true;
}

void Server::run() {
    if (::listen(socket, 0) < 0)  {
        Logger::log() << "Listen failed";
        return;
    }
    Logger::log() << "Listening...";
    while (true) {
        UnsafeConnection connection;
        sockaddr_in clientAddress = {};
        socklen_t socketSize = sizeof(clientAddress);
        connection.socket = ::accept(socket, (struct sockaddr *) &clientAddress, &socketSize);
        Logger::log() << "New connection accepted, creating new thread...";
        std::thread workerThread{ Worker(connection) };
        workerThread.detach();
    }
}
