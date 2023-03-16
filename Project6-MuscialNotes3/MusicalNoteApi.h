///  MusicalNoteApi.h
///  @brief Musical Notes Application Programming Interface (API) Header File
///  CPSC-298-6 Programming in C++ Project Musical Note Frequencies with Functions
///  @author cassriel@chapman.edu

#ifndef MusicalNoteApi_h
#define MusicalNoteApi_h
#include <iostream>
#include <cmath>

/// Number of semitones in an octave.
const static int k_semitones = 12;

/// Speed of sound in centimeters per second in air at standard temperature and pressure
const static double k_speedOfSoundCm = 34500.0;

/// Frequency of note C0; used as the reference frequency in computing the frequencies of other notes.
const static double k_referenceFrequency = 16.35;

/// Computes the frequency of a musical note given its octave and half-step (or semitone) number.
///
/// @param octave  integer from 0 to 11, inclusive, representing the half-step (or semitone) number within the octave.
/// @param semitone  integer > 0 representing the octave number of the note.
///
/// @pre octave integer  > 0
/// @pre semitone integer >= 0 and semitone < Number of Halftones (12)
///
/// @return double precision floating point value that is the frequency in Hertz (Hz), or
///         cycles per second, or -1.0 if an error occurred.
double getFrequency(int octave, int semitone);

/// Computes wavelength in centimeters of a musical note at room temperature and pressure given the note's frequency in Hertz.
///
/// @param frequency positive double precision value that is the frequency in Hertz (Hz) (non-negative, non-zero)
///
/// @pre frequency > 0.0 (i.e. non-zero and non-negative)
/// @pre frequency not a special floating point value such as positive or negative infinity, or a quiet or signaling NaN.
///
/// @return double precision value holding the computed wavelength in centimeters or -1.0 if an error occurred.
double getWavelength(double frequency);

/// Returns the shorthand name of the musical note whose octave and half-tone are specified.
/// @param octave integer > 0 representing the octave number of the note.
/// @param semitone  integer from 0 to 11, inclusive, representing the half-step (or semitone) number within the octave.
///
/// @pre octave  > 0
/// @pre semitone >= 0 and semitone < Number of Semitones (12)
///
/// @return a string object holding the shorthand name of the note corresponding to the specified
///         octave and half-tone, or "UNK" if octave and semitone are invalid.
std::string getNoteName(int octave, int semitone);

#endif /* MusicalNoteApi_h */
