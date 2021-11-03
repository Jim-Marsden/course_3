//
// Created by james on 10/29/2021.
//

#include "SineSignal.h"
#include <cmath>
#include <iostream>

Project2::SineSignal::SineSignal(double voltageOffset, const Time &timeOffset, double minVoltage, double maxVoltage,
                                 const Time &period) : PeriodicSignal(voltageOffset, timeOffset, minVoltage, maxVoltage,
                                                                      period) {}

auto Project2::SineSignal::getVoltageAtTime(const Time &t) const -> double {
    constexpr auto pi{3.14159265358979323846};

    const double min = getMinVoltage();
    const double max = getMaxVoltage();
    const auto max_from_min = [&min, &max]() { return max - min; }; // a lambda function ta
    auto result = getVoltageOffset() + min + max_from_min() / 2 +
           (std::sin((t.getTotalTimeAsSeconds() + getTimeOffset().getTotalTimeAsSeconds()) * 2 * (pi /
                getPeriod().getTotalTimeAsSeconds())) * max_from_min()) / 2;
    std::cout << result << '\n';

    return result;
}
