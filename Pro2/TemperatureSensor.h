//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_TEMPERATURESENSOR_H
#define COURSE_3_TEMPERATURESENSOR_H

#include "Sensor.h"

namespace Project2 {
    class TemperatureSensor : public Sensor {
    public:
        TemperatureSensor(const std::string &name, Signal &signal);

    private:
        auto getUnits() const -> std::string override;


    };
} // namespace Project2

#endif //COURSE_3_TEMPERATURESENSOR_H
