/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   19 Jan 2018
*/

#include <iostream>

#include "ATMSession.hpp"
#include "operations/CashWithdrawal.hpp"

ATMSession::ATMSession(BankAPI &api) : api(api){ }

bool ATMSession::run() {

    auto info = requestCardInfo();

    auto result = api.setClient(info);
    if (!result.success) {
        std::cout << result.message << std::endl;
        return false;
    }

    auto operation = requestOperation();
    bool status = operation != nullptr;
    if (status) status = operation->run(api);
    else {
        std::cout << "Operation unavailable" << std::endl;
    }

    return status;
}

CardInfo ATMSession::requestCardInfo() {
    CardInfo cardInfo;

    std::cout << "Enter the number card: ";
    std::cin >> cardInfo.card;
    std::cout << "Enter the pin: ";
    std::cin >> cardInfo.pin;

    return cardInfo;
}

std::unique_ptr<Operation> ATMSession::requestOperation() {
    std::cout << "Choose operation: " << std::endl;
    std::cout << "\t1. Cash Withdrawal" << std::endl;
    std::cout << "\t2. Card Replenishment" << std::endl;
    std::cout << "\t3. Balance" << std::endl;

    int choose = -1;
    std::cout << "Enter the number operation: ";
    std::cin >> choose;

    std::unique_ptr<Operation> result = nullptr;
    if (choose == 1) result = std::make_unique<CashWithdrawal>();

    return result;
}
