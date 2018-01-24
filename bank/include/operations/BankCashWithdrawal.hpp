/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   23 Jan 2018
*/

#pragma once

#include "Client.hpp"
#include "BankOperation.hpp"

class BankCashWithdrawal: public BankOperation {
public:
    BankCashWithdrawal(const std::string & cash);
    std::pair<bool, std::string> run() override;

private:
    std::string cash;
};

