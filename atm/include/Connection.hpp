/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   19 Jan 2018
*/

#pragma once


#include "Endpoint.hpp"

struct BaseConnection {
    virtual bool create(const Endpoint &endpoint) = 0;
    virtual bool write(const char *data, size_t size) = 0;
    virtual bool read(char *data, size_t &size) = 0;
    virtual bool close() = 0;
};

class UnsafeConnection : public BaseConnection {
public:
    bool create(const Endpoint &endpoint) override;
    bool write(const char *data, size_t size) override;
    bool read(char *data, size_t &size) override;
    bool close() override;
private:
    int socket = -1;
};

