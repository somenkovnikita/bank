/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   20 Jan 2018
*/

#pragma once


#include <string>

class Client {
public:
    Client() = default;
    Client(const std::string &number, short pin);

    bool load();
    bool save();

    bool isValidPin();
    float getCash();
    bool changeCash(float dcash);

    static void setBase(const std::string& base);

private:
    std::string number;
    float cash;
    short pin;

    static std::string base;
};

