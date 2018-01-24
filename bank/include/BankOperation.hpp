/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   23 Jan 2018
*/

#pragma once

#include <string>
#include "Client.hpp"

class BankOperation {
public:

    virtual std::pair<bool, std::string> run();

    void setClient(const Client &client);

private:
    bool isClientValid();

protected:
    Client client;
};

