//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// DataRecorder.h - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Handles logging and manages the output stream.
// The format for logging is:
// "{title} - {sensorname} - {voltage(0.00)} units\n"
// =======================================================================
//

#ifndef COURSE_3_DATARECORDER_H
#define COURSE_3_DATARECORDER_H
#include "Time.h"

#include <ostream>
#include <string>
namespace Project2 {
    class DataRecorder {
    public:
// [ Constructors / Destructors ] ======================================================= [ Constructors / Destructors ]
        explicit DataRecorder(std::ostream &out_in);

        DataRecorder() = delete;

        DataRecorder(DataRecorder const &) = delete;

        DataRecorder(DataRecorder &&) = default;

        ~DataRecorder() = default;
// [ Operators ] ========================================================================================= [ Operators ]

        DataRecorder &operator=(DataRecorder const &) = delete;

// [ Utilities ] ========================================================================================= [ Utilities ]
        void log(Time time, std::string sensorName, double sensorVoltage, std::string sensorUnits);

    private:
        std::ostream &out;

    };
} // namespace Project2

#endif //COURSE_3_DATARECORDER_H
