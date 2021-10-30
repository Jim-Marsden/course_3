//
// Created by james on 10/29/2021.
//

#include "SawtoothSignal.h"

Project2::SawtoothSignal::SawtoothSignal(double voltageOffset, const Time &timeOffset, double minVoltage,
                                         double maxVoltage, const Time &period) : PeriodicSignal(voltageOffset,
                                                                                                 timeOffset, minVoltage,
                                                                                                 maxVoltage, period) {}

auto Project2::SawtoothSignal::getVoltageAtTime(const Time &t) const -> double {
    return 0;
}
