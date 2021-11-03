//
// Created by james on 10/29/2021.
//

#include <cmath>
#include <iostream>
#include "SawtoothSignal.h"

Project2::SawtoothSignal::SawtoothSignal(double voltageOffset, const Time &timeOffset, double minVoltage,
                                         double maxVoltage, const Time &period) : PeriodicSignal(voltageOffset,
                                                                                                 timeOffset, minVoltage,
                                                                                                 maxVoltage, period) {}

auto Project2::SawtoothSignal::getVoltageAtTime(const Time &t) const -> double {
    const double voltage_offset = getVoltageOffset();
    const double min = getMinVoltage();
    const double max = getMaxVoltage();
    const double period = static_cast<double>(getPeriod().getTotalTimeAsSeconds());
    const double time_offset = static_cast<double>(this->getTimeOffset().getTotalTimeAsSeconds());

    return (voltage_offset + min) + fmod((t.getTotalTimeAsSeconds() + time_offset) * (max - min) / period, (max - min));
}