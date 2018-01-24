/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   23 Jan 2018
*/

#include <Client.hpp>
#include "BankOperation.hpp"

std::pair<bool, std::string> BankOperation::run() {
    if (!isClientValid()) {
        return {false, "Client not found"};
    }
    return {true, ""};
}

bool BankOperation::isClientValid() {
    return client.load() && client.isValidPin();
}

void BankOperation::setClient(const Client &client) {
    this->client = client;
}
