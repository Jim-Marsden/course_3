//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// DataRecorder.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Handles logging and manages the output stream.
// The format for logging is:
// "{title} - {sensorname} - {voltage(0.00)} units\n"
// =======================================================================
//

#include <iomanip>
#include "DataRecorder.h"

Project2::DataRecorder::DataRecorder(std::ostream &out_in) : out(out_in) {}

void Project2::DataRecorder::log(Time time, std::string sensorName, double sensorVoltage, std::string sensorUnits) {
    out << time <<  " - " << sensorName << " - " << std::fixed << std::setprecision(2) << sensorVoltage << ' ' << sensorUnits << '\n';

}
