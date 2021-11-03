//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_MONITORINGSYSTEM_H
#define COURSE_3_MONITORINGSYSTEM_H

#include <memory>
#include <vector>
#include "Sensor.h"

namespace Project2 {
    class MonitoringSystem {
    public:

        MonitoringSystem(std::ostream & stringstream);

        void addSensor(Sensor*);
        void takeReading(Project2::Time time);
    private:
        std::vector<Project2::Sensor*> sensors;
        DataRecorder dataRecorder;

    };

} // namespace Project2
#endif //COURSE_3_MONITORINGSYSTEM_H
