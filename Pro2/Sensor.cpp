//
// Created by james on 10/29/2021.
//

#include "Sensor.h"

Project2::Sensor::Sensor(std::string name, Project2::Signal &signal): name{name}, signal{signal} {}

std::string Project2::Sensor::getName() const {
    return name;
}

Project2::Signal &Project2::Sensor::getSignal() {
    return signal;
}

Project2::Signal const &Project2::Sensor::getSignal() const {
    return signal;
}

void Project2::Sensor::takeReading(Time time, Project2::DataRecorder &recorder) {
    recorder.log(time, getName(), getSignal().getVoltageAtTime(time), getUnits());
}

