//
// Created by Brian Cassriel on 4/19/23.
//

#include <iostream>
#include "ElectricControlUnit.h"

ElectricControlUnit::ElectricControlUnit() {
    activatedHydraulicJacks = false;
    activatedBeltTires = false;
    activatedIRIllumination = false;
}

ElectricControlUnit::~ElectricControlUnit() {

}

void ElectricControlUnit::handleCommand(char command) {
    switch(command) {
        case 'A':
        case 'a':
            actuateHydraulicJacks();
            break;
        case 'B':
        case 'b':
            actuateBeltTires();
            break;
        case 'E':
        case 'e':
            actuateIRIllumination();
            break;
    }
}

void ElectricControlUnit::actuateHydraulicJacks() {
    if (!activatedHydraulicJacks) {
        activatedHydraulicJacks = true;
        std::cout << "Hydraulic Jacks activated" << std::endl;
        if (activatedBeltTires) {
            activatedBeltTires = false;
            std::cout << "Belt Tires deactivated" << std::endl;
        }
    } else {
        activatedHydraulicJacks = false;
        std::cout << "Hydraulic Jacks deactivated" << std::endl;
    }

}

void ElectricControlUnit::actuateBeltTires() {
    if (!activatedBeltTires) {
        activatedBeltTires = true;
        std::cout << "Belt Tires activated" << std::endl;
    } else {
        activatedBeltTires = false;
        std::cout << "Belt Tires deactivated" << std::endl;
    }

}

void ElectricControlUnit::actuateIRIllumination() {
    if (!activatedIRIllumination) {
        activatedIRIllumination = true;
        std::cout << "Infrared Illumination activated" << std::endl;
    } else {
        activatedIRIllumination = false;
        std::cout << "Infrared Illumination deactivated" << std::endl;
    }

}