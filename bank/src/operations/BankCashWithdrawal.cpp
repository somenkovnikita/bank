/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   23 Jan 2018
*/

#include "BankOperation.hpp"
#include <Client.hpp>
#include "operations/BankCashWithdrawal.hpp"


BankCashWithdrawal::BankCashWithdrawal(const std::string &cash) : cash(cash) { }

std::pair<bool, std::string> BankCashWithdrawal::run() {
    auto result = BankOperation::run();
    if (result.first) return result;

    char *ptr = nullptr;
    double cashValue = strtod(cash.c_str(), &ptr);
    if (ptr == nullptr) {
        return {false, "Invalid sum"};
    }

    if (client.changeCash(-cashValue)) {
        return {false, "Insufficient funds or Invalid sum"};
    }

    client.save();
    return {true, std::to_string(cashValue) + " dollars are given out"};
}

