//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_MONITORINGSYSTEM_H
#define COURSE_3_MONITORINGSYSTEM_H

#include <memory>
#include <vector>

class MonitoringSystem {

private:
    std::vector<std::unique_ptr<Sensor>> sensors;
};


#endif //COURSE_3_MONITORINGSYSTEM_H
