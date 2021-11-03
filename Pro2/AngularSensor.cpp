//
// Created by james on 10/29/2021.
//

#include "AngularSensor.h"

Project2::AngularSensor::AngularSensor(const std::string& name, Project2::Signal& signal) : Sensor(name, signal) {}


std::string Project2::AngularSensor::getUnits() const {
    return std::string("Radians");
}

