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

#include "AngularSensor.h"

Project2::AngularSensor::AngularSensor(const std::string& name, Project2::Signal& signal) : Sensor(name, signal) {}


std::string Project2::AngularSensor::getUnits() const {
    return {"Radians"};
}

