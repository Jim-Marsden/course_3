//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// MonitoringSystem.h - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Handles managing all sensors and logging all sensors.
// =======================================================================
//

#ifndef COURSE_3_MONITORINGSYSTEM_H
#define COURSE_3_MONITORINGSYSTEM_H

#include <vector>
#include "Sensor.h"

namespace Project2 {
    class MonitoringSystem {
    public:
// [ Constructors / Destructors ] ======================================================= [ Constructors / Destructors ]
        explicit MonitoringSystem(std::ostream & ostream);
        ~MonitoringSystem() = default;

// [ Utilities ] ========================================================================================= [ Utilities ]
        void addSensor(Sensor*); // Adds the Sensor, but doesn't manage lifetime.
        void takeReading(Project2::Time time); // Prints the reading to dataRecorder
    private:

        std::vector<Project2::Sensor*> sensors;
        DataRecorder dataRecorder;

    };

} // namespace Project2
#endif //COURSE_3_MONITORINGSYSTEM_H
