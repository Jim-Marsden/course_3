//
// Created by james on 10/29/2021.
//

#include "ConstantSignal.h"

double Project2::ConstantSignal::getVoltageAtTime(const Time &time) const {
    return getVoltageOffset();
}

Project2::ConstantSignal::ConstantSignal( Project2::Time timeOffset, double voltageOffset) : Signal(timeOffset,
        voltageOffset){}
