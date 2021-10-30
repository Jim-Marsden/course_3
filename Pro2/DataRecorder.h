//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_DATARECORDER_H
#define COURSE_3_DATARECORDER_H
#include "Time.h"

#include <ostream>
#include <string>
namespace Project2 {
    class DataRecorder {
    public:

        explicit DataRecorder(std::ostream &out_in);

        DataRecorder() = delete;

        DataRecorder(DataRecorder const &) = delete;

        DataRecorder(DataRecorder &&) = default;

        ~DataRecorder() = default;

        DataRecorder &operator=(DataRecorder const &) = delete;

        void log(Time time, std::string sensorName, double sensorVoltage, std::string sensorUnits);

    private:
        std::ostream &out;

    };
} // namespace Project2

#endif //COURSE_3_DATARECORDER_H
