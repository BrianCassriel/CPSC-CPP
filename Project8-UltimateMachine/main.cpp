#include <iostream>
#include "UltimateMachine.h"
using namespace std;

int main() {
    cout << "The Ultimate Machine Simulation" << endl;
    UltimateMachine ultMachine;
    ultMachine.displayState();
    ultMachine.turnOn();
    return 0;
}
