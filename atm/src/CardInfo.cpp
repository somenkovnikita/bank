/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   19 Jan 2018
*/

#include "CardInfo.hpp"

#include <algorithm>


bool CardInfo::isValid() const {
    const bool isCardValid = std::all_of(
            card.begin(), card.end(), ::isdigit);

    return isCardValid || pin <= 9999;
}
