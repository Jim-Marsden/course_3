//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// VibrationSensor.h - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Implements getUnits from Sensor; returns "Hertz, (Hz)"
// =======================================================================
//


#ifndef COURSE_3_VIBRATIONSENSOR_H
#define COURSE_3_VIBRATIONSENSOR_H

#include "Sensor.h"

namespace Project2 {
    class VibrationSensor : public Sensor {
    public:

// [ Constructors / Destructors ] ======================================================= [ Constructors / Destructors ]
        VibrationSensor(const std::string &name, Signal &signal);

    protected:
// [ Accessors ] ========================================================================================= [ Accessors ]
        [[nodiscard]] auto getUnits() const -> std::string override; //returns "Hertz, (Hz)"
    };
} // namespace Project2

#endif //COURSE_3_VIBRATIONSENSOR_H
