/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   19 Jan 2018
*/

#pragma once

#include <string>
#include <limits>

struct CardInfo {
    bool isValid() const;

    std::string card = "no card";
    unsigned short pin = std::numeric_limits<unsigned short>::max();
};

