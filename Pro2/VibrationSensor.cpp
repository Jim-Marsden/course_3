//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// VibrationSensor.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Implements getUnits from Sensor; returns "Hertz, (Hz)
// =======================================================================
//

#include "VibrationSensor.h"

Project2::VibrationSensor::VibrationSensor(const std::string &name, Project2::Signal &signal) : Sensor(name, signal) {}

std::string Project2::VibrationSensor::getUnits() const {
    return "Hertz (Hz)";
}
