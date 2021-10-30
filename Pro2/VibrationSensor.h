//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_VIBRATIONSENSOR_H
#define COURSE_3_VIBRATIONSENSOR_H

#include "Sensor.h"

namespace Project2 {
    class VibrationSensor : public Sensor {
    public:
        VibrationSensor(const std::string &name, Signal &signal);

    protected:
        auto getUnits() const -> std::string override;
    };
} // namespace Project2

#endif //COURSE_3_VIBRATIONSENSOR_H
