//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// TemperatureSensor.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Overrides Sensor::getUnits to return "Degrees Celsius.
// =======================================================================
//

#include "TemperatureSensor.h"

Project2::TemperatureSensor::TemperatureSensor(const std::string &name, Project2::Signal &signal) : Sensor(name,
                                                                                                           signal) {}

std::string Project2::TemperatureSensor::getUnits() const {
    return "Degrees Celsius";
}
