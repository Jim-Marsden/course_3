//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_SENSOR_H
#define COURSE_3_SENSOR_H


#include "Signal.h"
#include "DataRecorder.h"

class Sensor {
public:
    Sensor(std::string name, Signal & signal);
    void takeReadings(Time time, DataRecorder & recorder);

protected:
    virtual std::string getUnits()=0;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] Signal & getSignal();
    [[nodiscard]] Signal const & getSignal() const;
private:
    Signal & signal;
    std::string name;
};


#endif //COURSE_3_SENSOR_H
