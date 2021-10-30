//
// Created by james on 10/29/2021.
//

#include "Signal.h"

Project2::Signal::Signal(Time timeOffset, double voltageOffset) : timeOffset(timeOffset), voltageOffset(voltageOffset) {}

double Project2::Signal::getVoltageOffset() const {
    return voltageOffset;
}

Project2::Time Project2::Signal::getTimeOffset() const {
    return timeOffset;
}
