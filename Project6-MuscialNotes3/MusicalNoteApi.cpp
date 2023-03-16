///  MusicalNoteApi.cpp
///  @brief Musical Notes Application Programming Interface (API) Implementation File
///  CPSC-298-6 Programming in C++ Project Musical Note Frequencies with Functions
///  @author cassriel@chapman.edu

#include "MusicalNoteApi.h"
using namespace std;

double getFrequency(int octave, int semitone) {
    if (!(octave >= 0 && (semitone >= 0 && semitone < k_semitones))) {
        cerr << "ERROR: getFrequency preconditions not satisfied; FrequencyHz octave (" << octave << ") or semitone (" << semitone << ") invalid" << endl;
        return -1.0;
    }
    return k_referenceFrequency * pow(2, octave + (semitone / 12.0));
}

double getWavelength(double frequency) {
    if ((frequency < 0.0) || (!std::isfinite(frequency)) || (FP_ZERO == std::fpclassify(frequency)))
    {
        cerr << "ERROR: getWavelength preconditions not satisfied; frequency invalid: " << frequency << endl;
        return -1.0;
    }
    return k_speedOfSoundCm / frequency;
}

string getNoteName(int octave, int semitone) {
    const static string a_notePrefix[] = {
            "C", "C#", "D","D#", "E", "F", "F#", "G", "G#", "A", "A#", "B",
    };
    
    if (!(octave >= 0 && (semitone >= 0 && semitone < k_semitones)))
        return "UNK";
    return a_notePrefix[semitone] + to_string(octave);
}

int main(int argc, const char * argv[]) {
    int octaves = 11;
    double frequency;
    double wavelengthCm;
    string noteName;
    
    for (int octave = 0; octave < octaves; octave++)
    {
        for (int semitone = 0; semitone < k_semitones; semitone++)
        {
            frequency = getFrequency(octave, semitone);
            wavelengthCm = getWavelength(frequency);
            noteName = getNoteName(octave, semitone);
            cout << "Note: " << noteName << "; nu: " << octave << "; k: " << semitone
                << "; frequency: " << frequency << " Hz; wavelength: "
                << wavelengthCm << " cm" << std::endl;
        }
    }
    
    cout << endl << endl;
    cout << "----------------------------- CHECK ERROR HANDLING -----------------------------" << endl;
    
    frequency = getFrequency(-1, -1);
    wavelengthCm = getWavelength(-16.35);
    noteName = getNoteName(-1, -1);
    
    cout << "Note: " << noteName << "; nu: -1; k: -1; frequency: " << frequency << " Hz; wavelength: " << wavelengthCm << " cm" << endl;
    
    return 0;
}
