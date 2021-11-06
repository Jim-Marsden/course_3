//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// SineSignal.h - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Override from PeriodicSignal to allow for a sine waveform.
// =======================================================================
//
#include "SineSignal.h"
#include <cmath> // for std::sin

Project2::SineSignal::SineSignal(double voltageOffset, const Time &timeOffset, double minVoltage, double maxVoltage,
                                 const Time &period) : PeriodicSignal(voltageOffset, timeOffset, minVoltage, maxVoltage,
                                                                      period) {}

auto Project2::SineSignal::getVoltageAtTime(const Time &t) const -> double {
    constexpr auto pi{3.14159265358979323846};

    const double min = getMinVoltage();
    const double max = getMaxVoltage();
    const auto max_from_min = [&min, &max]() { return max - min; }; // a lambda function to ensure min, and max's values are always correct.
    auto result = getVoltageOffset() + min + max_from_min() / 2 +
                  (std::sin((static_cast<double>(t) + static_cast<double>(getTimeOffset())) * 2 *
                            (pi / static_cast<double>(getPeriod()))) *
                   max_from_min()) / 2;
    return result;
}
