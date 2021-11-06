//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// PeriodicSignal.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Abstract class for more variable signals, such as a sine waveform, or
// a sawtooth wave for example.
// =======================================================================
//

#include "PeriodicSignal.h"

auto Project2::PeriodicSignal::getMinVoltage() const -> double {
    return minVoltage;
}

auto Project2::PeriodicSignal::getMaxVoltage() const -> double {
    return maxVoltage;
}

auto Project2::PeriodicSignal::getPeriod() const -> Time {
    return period;
}

Project2::PeriodicSignal::PeriodicSignal(double voltageOffset, const Time &timeOffset, double minVoltage,
                                         double maxVoltage, Time period) : Signal(timeOffset, voltageOffset),
                                                                           minVoltage{minVoltage},
                                                                           maxVoltage{maxVoltage},
                                                                           period(period) {}


