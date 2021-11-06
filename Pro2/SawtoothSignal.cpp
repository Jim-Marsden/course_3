//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// Sawtooth.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Implements the abstract class -- PeriodicSignal. Generates a
// Triangle waves by implementing PeriodicSignal::getVoltageAtTime
// =======================================================================
//

#include <cmath> // for std::fmod
#include "SawtoothSignal.h"

Project2::SawtoothSignal::SawtoothSignal(double voltageOffset, const Time &timeOffset, double minVoltage,
                                         double maxVoltage, const Time &period) : PeriodicSignal(voltageOffset,
                                                                                                 timeOffset, minVoltage,
                                                                                                 maxVoltage, period) {}

auto Project2::SawtoothSignal::getVoltageAtTime(const Time &t) const -> double {
    const double min = getMinVoltage();
    const double max = getMaxVoltage();
    // A lambda to ensure that if min or max ever change in the future, the value will always be correct. As an example, const_cast<>.
    auto max_from_min = [&min, &max]() {
        return max - min;
    };

    return (getVoltageOffset() + min) + std::fmod(
            (static_cast<double>(t) + static_cast<double>(getTimeOffset())) * (max_from_min()) /
            static_cast<double>(getPeriod()), (max_from_min()));
}