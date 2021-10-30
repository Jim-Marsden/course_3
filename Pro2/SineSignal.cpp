//
// Created by james on 10/29/2021.
//

#include "SineSignal.h"

Project2::SineSignal::SineSignal(double voltageOffset, const Time &timeOffset, double minVoltage, double maxVoltage,
                                 const Time &period) : PeriodicSignal(voltageOffset, timeOffset, minVoltage, maxVoltage,
                                                                      period) {}

auto Project2::SineSignal::getVoltageAtTime(const Time &t) const -> double {
    return 0;
}
