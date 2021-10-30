//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_PERIODICSIGNAL_H
#define COURSE_3_PERIODICSIGNAL_H

#include "Signal.h"

namespace Project2 {
    class PeriodicSignal :public Signal {
    public:
//        PeriodicSignal(double voltageOffset, const Time &timeOffset);
        PeriodicSignal(double voltageOffset, const Time &timeOffset, double minVoltage, double maxVoltage, Time period);

    protected:
        auto getMinVoltage() const -> double;
        auto getMaxVoltage() const -> double;
        auto getPeriod() -> Time;

    private:
        double minVoltage;
        double maxVoltage;
        Time period;

    };
} // namespace Project2

#endif //COURSE_3_PERIODICSIGNAL_H
