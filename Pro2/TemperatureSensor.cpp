//
// Created by james on 10/29/2021.
//

#include "TemperatureSensor.h"

Project2::TemperatureSensor::TemperatureSensor(const std::string &name, Project2::Signal &signal) : Sensor(name,
                                                                                                           signal) {}

std::string Project2::TemperatureSensor::getUnits() const {
    return "Degrees Celsius";
}
