//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// TemperatureSensor.h - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Overrides Sensor::getUnits to return "Degrees Celsius.
// =======================================================================
//
#ifndef COURSE_3_TEMPERATURESENSOR_H
#define COURSE_3_TEMPERATURESENSOR_H

#include "Sensor.h"

namespace Project2 {
    class TemperatureSensor : public Sensor {
    public:
        TemperatureSensor(const std::string &name, Signal &signal);
// [ Constructors / Destructors ] ======================================================= [ Constructors / Destructors ]

    private:
// [ Accessors ] ========================================================================================= [ Accessors ]
        auto getUnits() const -> std::string override;


    };
} // namespace Project2

#endif //COURSE_3_TEMPERATURESENSOR_H
