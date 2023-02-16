//
//  main.cpp
//  MusicalNotes
//
//  Created by Brian Cassriel on 2/15/23.
//

#include <iostream>
#include <cmath>
using namespace std;

double computeWavelength(int SPEED_OF_SOUND_CM, double frequency) {
    return SPEED_OF_SOUND_CM / frequency;
}

double computeFrequency(double referenceFrequency, int octave, int semitone, double TWELTH_ROOT_OF_TWO) {
    double finalFrequency = referenceFrequency * pow(2, octave) * pow(TWELTH_ROOT_OF_TWO, semitone);
    return finalFrequency;
}

int main () {
    double referenceFrequency = 16.35; // C0
    const double SPEED_OF_SOUND_CM = 34500; // centimeters/second
    const double TWELTH_ROOT_OF_TWO = pow(2, 1/12.0);
    
    cout << "Reference Frequency: " << referenceFrequency << endl;
    double currentFrequency;
    
    currentFrequency = computeFrequency(referenceFrequency, 0, 0, TWELTH_ROOT_OF_TWO);
    cout << "C  0: " << "octave: " << 0 << " semitone: " << 0 << " "
    << "frequency: " << currentFrequency << " Hz "
    << "wavelength: " << computeWavelength(SPEED_OF_SOUND_CM, currentFrequency) << " cm" << endl;
    
    currentFrequency = computeFrequency(referenceFrequency, 0, 1, TWELTH_ROOT_OF_TWO);
    cout << "C# 0: " << "octave: " << 0 << " semitone " << 1 << " "
    << "frequency: " << currentFrequency << " Hz "
    << "wavelength: " << computeWavelength(SPEED_OF_SOUND_CM, currentFrequency) << " cm" << endl;
    
    currentFrequency = computeFrequency(referenceFrequency, 0, 2, TWELTH_ROOT_OF_TWO);
    cout << "D  0: " << "octave: " << 0 << " semitone " << 2 << " "
    << "frequency: " << currentFrequency << " Hz "
    << "wavelength: " << computeWavelength(SPEED_OF_SOUND_CM, currentFrequency) << " cm" << endl;
    
    currentFrequency = computeFrequency(referenceFrequency, 4, 0, TWELTH_ROOT_OF_TWO);
    cout << "C  4: " << "octave: " << 4 << " semitone " << 0 << " "
    << "frequency: " << currentFrequency << " Hz "
    << "wavelength: " << computeWavelength(SPEED_OF_SOUND_CM, currentFrequency) << " cm" << endl;
    
    currentFrequency = computeFrequency(referenceFrequency, 7, 3, TWELTH_ROOT_OF_TWO);
    cout << "D# 7: " << "octave: " << 7 << " semitone " << 3 << " "
    << "frequency: " << currentFrequency << " Hz "
    << "wavelength: " << computeWavelength(SPEED_OF_SOUND_CM, currentFrequency) << " cm" << endl;
    
    currentFrequency = computeFrequency(referenceFrequency, 8, 0, TWELTH_ROOT_OF_TWO);
    cout << "C  8: " << "octave: " << 8 << " semitone " << 0 << " "
    << "frequency: " << currentFrequency << " Hz "
    << "wavelength: " << computeWavelength(SPEED_OF_SOUND_CM, currentFrequency) << " cm" << endl;
    
    return 0;
}
