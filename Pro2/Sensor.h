//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// Sensor.h - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Abstract class for handling sensor-types. The most basal Sensor type.
// It holds a Signal object that contains the information to be logged.
// =======================================================================
//


#ifndef COURSE_3_SENSOR_H
#define COURSE_3_SENSOR_H


#include "Signal.h"
#include "DataRecorder.h"

namespace Project2 {
    class Sensor {
    public:
// [ Constructors / Destructors ] ======================================================= [ Constructors / Destructors ]

        Sensor(std::string name, Project2::Signal &signal);
// [ Utilities ] ========================================================================================= [ Utilities ]
        void takeReading(Time time, Project2::DataRecorder &recorder);

    protected:
// [ Accessors ] ========================================================================================= [ Accessors ]
        //The units will be implemented by the derived classes, as a way to takeReading for
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
