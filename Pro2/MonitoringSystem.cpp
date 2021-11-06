//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// MonitoringSystem.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Handles managing all sensors and logging all sensors.
// =======================================================================
//

#include "MonitoringSystem.h"

Project2::MonitoringSystem::MonitoringSystem(std::ostream &out) : dataRecorder(out) {}

void Project2::MonitoringSystem::takeReading(Project2::Time time) {
    for(auto const & element : sensors){
        element->takeReading(time, dataRecorder);
    }

}

void Project2::MonitoringSystem::addSensor(Project2::Sensor * new_sensor) {
    sensors.emplace_back(new_sensor);
}
