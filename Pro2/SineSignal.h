//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_SINESIGNAL_H
#define COURSE_3_SINESIGNAL_H


#include "PeriodicSignal.h"

namespace Project2 {
    class SineSignal : public PeriodicSignal {
    public:
        SineSignal(double voltageOffset, const Time &timeOffset, double minVoltage, double maxVoltage,
                   const Time &period);

        [[nodiscard]] auto getVoltageAtTime(Time const & t) const -> double override;
    };
} // namespace Project2

#endif //COURSE_3_SINESIGNAL_H
