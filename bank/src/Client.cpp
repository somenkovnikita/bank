/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   20 Jan 2018
*/

#include "Client.hpp"

Client::Client(const std::string &number, short pin) : number(number), pin(pin) { }

bool Client::load() {
    return false;
}

bool Client::save() {
    return false;
}

bool Client::isValidPin() {
    return false;
}

float Client::getCash() {
    return 0;
}

bool Client::changeCash(float dcash) {
    return false;
}

void Client::setBase(const std::string &base) {

}
