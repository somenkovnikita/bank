/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   19 Jan 2018
*/

#include <iostream>
#include <vector>

#include "operations/CashWithdrawal.hpp"

CashWithdrawal::CashWithdrawal() {
    std::cout << "Enter amount: ";
    std::cin >> cash;
}

std::string CashWithdrawal::name() const {
    return "Cash Withdrawal";
}

bool CashWithdrawal::run(BankAPI &api) {

    auto response = api.getCash(cash);

    if (!response.success) {
        std::cout << response.message << std::endl;
        return false;
    }

    return true;

}
