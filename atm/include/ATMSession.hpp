/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   19 Jan 2018
*/

#pragma once


#include <memory>

#include "Operation.hpp"
#include "BankAPI.hpp"

class ATMSession {
public:
    explicit ATMSession(BankAPI &api);
    bool run();

    CardInfo requestCardInfo();
    std::unique_ptr<Operation> requestOperation();

public:
    BankAPI &api;
};

