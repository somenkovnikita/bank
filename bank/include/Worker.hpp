/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   20 Jan 2018
*/

#pragma once

#include "Connection.hpp"
#include "Client.hpp"
#include "BankOperation.hpp"

class Worker {
public:
    Worker(BaseConnection &connection);
    void operator()();

private:
    std::unique_ptr<BankOperation> chooseOperation(const std::string &command);
    std::pair<Client, std::string> parse(const std::string &query);
    std::string readQuery();
    bool sendResponse(const std::pair<bool, std::string> &);

    BaseConnection &connection;
    std::string id;
};

