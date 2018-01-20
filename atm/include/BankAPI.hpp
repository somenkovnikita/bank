/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   20 Jan 2018
*/

#pragma once


#include "Endpoint.hpp"
#include "Connection.hpp"
#include "CardInfo.hpp"

struct Responce {
    bool success = false;
    std::string message = "";
};

class BankAPI {
public:
    explicit BankAPI(const Endpoint &endpoint, BaseConnection &&connection = UnsafeConnection());

    Responce setClient(const CardInfo &info);

    Responce getCash(float amount);
    Responce addCash(float amount);
    Responce cash(float &amount);

private:
    Responce makeQuery(const std::string &query);

    BaseConnection &connection;
    std::string clientid;
    Endpoint endpoint;
};

