//
// Created by james on 10/29/2021.
//

#include "DataRecorder.h"

DataRecorder::DataRecorder(std::ostream &out_in) : out(out_in) {

}

void DataRecorder::log(Time time, std::string sensorName, double sensorVoltage, std::string sensorUnits) {
    out << time << sensorName << sensorVoltage << sensorUnits << '\n';
}
