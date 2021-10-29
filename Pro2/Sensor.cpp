//
// Created by james on 10/29/2021.
//

#include "Sensor.h"

Sensor::Sensor(std::string name, Signal &signal): name{name}, signal{signal} {}

std::string Sensor::getName() const {
    return name;
}

Signal &Sensor::getSignal() {
    return signal;
}

Signal const &Sensor::getSignal() const {
    return signal;
}

