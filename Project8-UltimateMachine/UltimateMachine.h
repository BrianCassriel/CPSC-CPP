//
// Created by Brian Cassriel on 3/29/23.
//

#ifndef ULTIMATEMACHINE_ULTIMATEMACHINE_H
#define ULTIMATEMACHINE_ULTIMATEMACHINE_H

class UltimateMachine {
public:
    UltimateMachine();
    ~UltimateMachine();
    void displayState();
    void turnOn();
private:
    bool isOn;
};

#endif //ULTIMATEMACHINE_ULTIMATEMACHINE_H
