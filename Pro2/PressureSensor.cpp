//
// Created by james on 10/29/2021.
//

#include "PressureSensor.h"

Project2::PressureSensor::PressureSensor(const std::string &name, Project2::Signal &signal) : Sensor(name, signal) {}

std::string Project2::PressureSensor::getUnits() const {
    return "Pounds per square inch (PSI)";
}
