//
// Created by james on 10/29/2021.
//

#include "VibrationSensor.h"

Project2::VibrationSensor::VibrationSensor(const std::string &name, Project2::Signal &signal) : Sensor(name, signal) {}

std::string Project2::VibrationSensor::getUnits() const {
    return "Hertz (Hz)";
}
