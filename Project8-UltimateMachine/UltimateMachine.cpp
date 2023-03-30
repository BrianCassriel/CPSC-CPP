//
// Created by Brian Cassriel on 3/29/23.
//

#include <iostream>
#include "UltimateMachine.h"

using namespace std;

UltimateMachine::UltimateMachine() : isOn(false) {
    cout << "UltimateMachine constructor (ctor) called." << endl;
}

UltimateMachine::~UltimateMachine() {
    cout << "UltimateMachine destructor (dtor) called." << endl;
}

void UltimateMachine::displayState() {
    switch (isOn) {
        case true:
            cout << "Ultimate Machine is ON" << endl;
            break;
        case false:
            cout << "Ultimate Machine is OFF" << endl;
            break;
    }
}

void UltimateMachine::turnOn() {
    isOn = true;
    displayState();
    isOn = false;
    displayState();
}

