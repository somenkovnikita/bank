/**
*   @author Nikita Somenkov
*   @email somenkov.nikita@icloud.com
*   @date   19 Jan 2018
*/

#include <iostream>
#include <BankAPI.hpp>

#include "ATMSession.hpp"
#include "Endpoint.hpp"

void usage() {
    std::cout << "amt <connection-config>" << std::endl;
}

void sayHello() {
    std::cout << " #     #                                            \n"
                 " ##    #   ##   #####  ######      # #    # # #   # \n"
                 " # #   #  #  #  #    # #           # ##   # #  # #  \n"
                 " #  #  # #    # #    # #####       # # #  # #   #   \n"
                 " #   # # ###### #    # #           # #  # # #   #   \n"
                 " #    ## #    # #    # #      #    # #   ## #   #   \n"
                 " #     # #    # #####  ######  ####  #    # #   #   \n";
}

void sayGoodBay() {
    std::cout << "Have a good mood!" << std::endl;
}

void nearestBankomat() {
    std::cout << "Sorry, but the ATM does not work" << std::endl;
    std::cout << "List of nearest ATMs: " << std::endl;
    std::cout << "\t-Nevka, 53" << std::endl;
    std::cout << "\t-Lusika, 106" << std::endl;
    std::cout << "\t-Rubacheva, 2" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        usage();
        return -1;
    }

    Endpoint bankApiEndpoint;
    if (!bankApiEndpoint.readEndpoint(argv[1])) {
        std::cout << "not valid config";
        return -2;
    }

    std::cout << "Connection with bank...";
    BankAPI api(bankApiEndpoint);

    sayHello();
    while (true) {
        ATMSession session(api);
        if (session.run()) {
            std::cout << "Thank you!" << std::endl;
        } else {
            nearestBankomat();
        }

        sayGoodBay();
        std::cout << std::endl << std::endl;
        sayHello();
    }

    return 0;
}

