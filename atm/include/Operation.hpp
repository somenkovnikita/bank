/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   19 Jan 2018
*/

#pragma once

#include <string>

#include "BankAPI.hpp"

class Operation {
public:

    virtual std::string name() const = 0;
    virtual bool run(BankAPI &api) = 0;
};
