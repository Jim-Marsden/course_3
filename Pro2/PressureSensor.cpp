//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// PressureSensor.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Implements Sensor with the unit "Pounds per square inch (PSI)"
// =======================================================================
//

#include "PressureSensor.h"

Project2::PressureSensor::PressureSensor(const std::string &name, Project2::Signal &signal) : Sensor(name, signal) {}

std::string Project2::PressureSensor::getUnits() const {
    return "Pounds per square inch (PSI)";
}
