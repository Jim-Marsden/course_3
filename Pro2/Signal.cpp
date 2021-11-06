//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// Signal.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// The most basal abstract class that handles the most basal form of
// signaling.
// =======================================================================
//


#include "Signal.h"

Project2::Signal::Signal(Time timeOffset, double voltageOffset) : timeOffset(timeOffset), voltageOffset(voltageOffset) {}

double Project2::Signal::getVoltageOffset() const {
    return voltageOffset;
}

Project2::Time Project2::Signal::getTimeOffset() const {
    return timeOffset;
}
