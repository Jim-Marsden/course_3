//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// ConstantSignal.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Implements the virtual Signal object and implements a constant
// ConstantSignal::getVoltageAtTime to return a constant voltage based on
// the offset
// =======================================================================
//


#include "ConstantSignal.h"

double Project2::ConstantSignal::getVoltageAtTime(const Time &time) const {
    return getVoltageOffset();
}

Project2::ConstantSignal::ConstantSignal(double voltageOffset, Project2::Time timeOffset) : Signal(timeOffset,
        voltageOffset){}
