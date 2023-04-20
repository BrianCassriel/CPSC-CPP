//
// Created by Brian Cassriel on 4/19/23.
//

#ifndef ELECTRONICCONTROLUNIT_ELECTRICCONTROLUNIT_H
#define ELECTRONICCONTROLUNIT_ELECTRICCONTROLUNIT_H


class ElectricControlUnit {
public:
    ElectricControlUnit();
    ~ElectricControlUnit();
    void handleCommand(char command);

private:
    bool activatedHydraulicJacks; // Button A
    bool activatedBeltTires;        // Button B
    bool activatedIRIllumination;   // Button C

    void actuateHydraulicJacks();
    void actuateBeltTires();
    void actuateIRIllumination();
};


#endif //ELECTRONICCONTROLUNIT_ELECTRICCONTROLUNIT_H
