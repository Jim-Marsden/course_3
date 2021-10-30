//
// Created by james on 10/29/2021.
//

#include "PeriodicSignal.h"

auto Project2::PeriodicSignal::getMinVoltage() const -> double {
    return minVoltage;
}

auto Project2::PeriodicSignal::getMaxVoltage() const -> double {
    return maxVoltage;
}

auto Project2::PeriodicSignal::getPeriod() -> Time {
    return period;
}

Project2::PeriodicSignal::PeriodicSignal(double voltageOffset, const Time &timeOffset, double minVoltage,
                                         double maxVoltage, Time period) : Signal(timeOffset, voltageOffset),
                                                                           minVoltage{minVoltage},
                                                                           maxVoltage{maxVoltage},
                                                                           period(period) {}


