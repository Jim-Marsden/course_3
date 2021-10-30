//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_SENSOR_H
#define COURSE_3_SENSOR_H


#include "Signal.h"
#include "DataRecorder.h"

namespace Project2 {
    class Sensor {
    public:
        Sensor(std::string name, Project2::Signal &signal);

        void takeReading(Time time, Project2::DataRecorder &recorder);

    protected:
        [[nodiscard]] virtual auto getUnits() const  ->  std::string = 0;

        [[nodiscard]] auto getName() const -> std::string;

        [[nodiscard]] auto getSignal() -> Signal&;

        [[nodiscard]] auto getSignal() const -> Signal const &;

    private:
        Signal &signal;
        std::string name;
    };
} // namespace Project2

#endif //COURSE_3_SENSOR_H
