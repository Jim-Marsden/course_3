//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// PressureSensor.h - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Implements Sensor with the unit "Pounds per square inch (PSI)"
// =======================================================================
//

#ifndef COURSE_3_PRESSURESENSOR_H
#define COURSE_3_PRESSURESENSOR_H

#include "Sensor.h"

namespace Project2 {
    class PressureSensor : public Sensor{
    public:
// [ Constructors / Destructors ] ======================================================= [ Constructors / Destructors ]
        PressureSensor(const std::string &name, Signal &signal);

    protected:
// [ Accessors ] ========================================================================================= [ Accessors ]
        [[nodiscard]] std::string getUnits() const override; // returns "Pounds per square inch (PSI)"

    };
} // namespace Project2

#endif //COURSE_3_PRESSURESENSOR_H
