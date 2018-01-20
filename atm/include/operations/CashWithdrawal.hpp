/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   19 Jan 2018
*/

#pragma once

#include "Operation.hpp"

class CashWithdrawal : public Operation {
public:
    CashWithdrawal();

    std::string name() const override;

    bool run(BankAPI &api) override;

private:
    float cash;
};

