//
// Created by james on 10/29/2021.
//

#include "MonitoringSystem.h"

Project2::MonitoringSystem::MonitoringSystem(std::ostream &out) : dataRecorder(out) {

}

void Project2::MonitoringSystem::takeReading(Project2::Time time) {

}

void Project2::MonitoringSystem::addSensor(Project2::Sensor * new_sensor) {
    sensors.emplace_back(new_sensor);

}
