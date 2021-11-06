//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// AngularSensor.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Implements the virtual Sensor object and returns the appropriate unites
// ("Radians")
// =======================================================================
//

#ifndef COURSE_3_ANGULARSENSOR_H
#define COURSE_3_ANGULARSENSOR_H

#include "Sensor.h"

namespace Project2 {
    class AngularSensor : public Sensor {

    public:

    protected:
    public:
        //[ Constructors/ Destructors ] ================================== [ Constructors/ Destructors ] 
        AngularSensor(const std::string &name, Signal &signal);
        AngularSensor(AngularSensor const&) = default;
        AngularSensor(AngularSensor  &&) = default;
        ~AngularSensor() = default;

        //[ Operators ] ================================== [ Operators ] 
        AngularSensor() = delete;


    protected:
        // [ Private Accessors ] ==========================================[ Private Accessors ]
        [[nodiscard]] std::string getUnits() const override; // Should return "Radians"
    };
}

#endif //COURSE_3_ANGULARSENSOR_H
