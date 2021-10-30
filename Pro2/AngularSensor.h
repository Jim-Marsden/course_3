//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_ANGULARSENSOR_H
#define COURSE_3_ANGULARSENSOR_H

#include "Sensor.h"

namespace Project2 {
    class AngularSensor : public Sensor {

    public:

    protected:
    public:
        AngularSensor(const std::string &name, Signal &signal);

        AngularSensor(AngularSensor const&) = default;
        AngularSensor() = delete;
        AngularSensor(AngularSensor  &&) = default;
        ~AngularSensor() = default;

    protected:
        [[nodiscard]] std::string getUnits() const override;
    };
}

#endif //COURSE_3_ANGULARSENSOR_H
