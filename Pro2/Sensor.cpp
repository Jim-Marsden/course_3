//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// Sensor.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Abstract class for handling sensor-types. The most basal Sensor type.
// It holds a Signal object that contains the information to be logged.
// =======================================================================
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
    //DataRecorder::log's format - "{title} - {sensorname} - {voltage(0.00)} units\n"
    recorder.log(time, getName(), getSignal().getVoltageAtTime(time), getUnits());
}

