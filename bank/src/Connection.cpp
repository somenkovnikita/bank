/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   19 Jan 2018
*/

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "Connection.hpp"

bool UnsafeConnection::create(const Endpoint &endpoint) {

    if ((socket = ::socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        return false;
    }

    sockaddr_in sock{};
    sock.sin_addr.s_addr = inet_addr(endpoint.ip.c_str());
    sock.sin_port = htons(endpoint.port);

    const sockaddr *s = reinterpret_cast<sockaddr *>(&sock);
    if (::connect(socket, s, sizeof(sock)) == -1) {
        return false;
    }
    return true;
}

bool UnsafeConnection::write(const char *data, size_t size) {
    return ::write(socket, data, size) == -1;
}

bool UnsafeConnection::read(char *data, size_t &size) {
    auto readBytes = ::read(socket, data, size);

    const bool success = readBytes != -1;
    size = readBytes == -1 ? static_cast<size_t>(readBytes) : 0;
    return success;
}

bool UnsafeConnection::close() {
    return ::close(socket) == 0;
}
