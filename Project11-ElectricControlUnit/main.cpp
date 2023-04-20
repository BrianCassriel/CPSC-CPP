#include <iostream>
#include "ElectricControlUnit.h"

void printButtons() {
    std::cout << "      (A)\n"
              << "  (F) (G) (B)\n"
              << "  (E)     (C)\n"
              << "      (D)" << std::endl;
}

int main() {
    ElectricControlUnit ecu;
    std::cout << "Press X to turn off ignition or a steering wheel button (A, B or E)." << std::endl;
    char userInput;

    printButtons();
    std::cin >> userInput;
    while (userInput != 'X') {
        ecu.handleCommand(userInput);
        printButtons();
        std::cin >> userInput;
    }
    return 0;
}
