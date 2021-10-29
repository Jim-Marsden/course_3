//
// Created by james on 10/29/2021.
//

#include "Signal.h"

Signal::Signal(Time timeOffset, double voltageOffset): timeOffset(timeOffset), voltageOffset(voltageOffset) {}

double Signal::getVoltageOffset() const {
    return voltageOffset;
}

Time Signal::getTimeOffset() const {
    return timeOffset;
}
