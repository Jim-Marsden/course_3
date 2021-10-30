//
// Created by james on 10/29/2021.
//

#include "ConstantSignal.h"

//Project2::ConstantSignal::ConstantSignal(double voltageOffset, const Time &timeOffset) : Signal(timeOffset,
//                                                                                                voltageOffset) {}

double Project2::ConstantSignal::getVoltageAtTime(const Time &time) const {
    return this->getVoltageOffset() * getVoltageOffset();
}

Project2::ConstantSignal::ConstantSignal( Project2::Time timeOffset, double voltageOffset) : Signal(timeOffset,
        voltageOffset){}
