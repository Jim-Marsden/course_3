//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_PRESSURESENSOR_H
#define COURSE_3_PRESSURESENSOR_H

#include "Sensor.h"

namespace Project2 {
    class PressureSensor : public Sensor{
    public:
        PressureSensor(const std::string &name, Signal &signal);

    protected:
        [[nodiscard]] std::string getUnits() const override;

    };
} // namespace Project2

#endif //COURSE_3_PRESSURESENSOR_H
