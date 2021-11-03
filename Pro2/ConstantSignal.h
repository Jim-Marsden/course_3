//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_CONSTANTSIGNAL_H
#define COURSE_3_CONSTANTSIGNAL_H


#include "Signal.h"

namespace Project2 {
    class ConstantSignal : public Signal {
    public:
        ConstantSignal(  Time timeOffset, double voltageOffset);
        [[nodiscard]] double getVoltageAtTime(Time const & time) const override;

    };

 } // namespace Project2
#endif //COURSE_3_CONSTANTSIGNAL_H
