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
        //[ Constructors/ Destructors ] ================================== [ Constructors/ Destructors ] 
        AngularSensor(const std::string &name, Signal &signal);
        AngularSensor(AngularSensor const&) = default;
        AngularSensor(AngularSensor  &&) = default;
        ~AngularSensor() = default;

        //[ Operators ] ================================== [ Operators ] 
        AngularSensor() = delete;


    protected:
        // [ Private Accessors ] ==========================================[ Private Accessors ]
        [[nodiscard]] std::string getUnits() const override; // Should return "Radians"
    };
}

#endif //COURSE_3_ANGULARSENSOR_H
