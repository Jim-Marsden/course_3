//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_SAWTOOTHSIGNAL_H
#define COURSE_3_SAWTOOTHSIGNAL_H

#include "PeriodicSignal.h"

namespace Project2 {
    class SawtoothSignal : public PeriodicSignal{
    public:
        SawtoothSignal(double voltageOffset, const Time &timeOffset, double minVoltage, double maxVoltage,
                       const Time &period);

        [[nodiscard]] auto getVoltageAtTime(Time const & t) const  -> double override;

    };
} // namespace Project2

#endif //COURSE_3_SAWTOOTHSIGNAL_H
