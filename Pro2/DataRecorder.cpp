//
// Created by james on 10/29/2021.
//

#include <iostream>
#include <iomanip>
#include "DataRecorder.h"

Project2::DataRecorder::DataRecorder(std::ostream &out_in) : out(out_in) {

}

void Project2::DataRecorder::log(Time time, std::string sensorName, double sensorVoltage, std::string sensorUnits) {
    out << time <<  " - " << sensorName << " - " << std::fixed << std::setprecision(2) << sensorVoltage << ' ' << sensorUnits << '\n';

}
