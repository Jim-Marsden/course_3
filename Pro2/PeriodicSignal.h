//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// PeriodicSignal.h - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Abstract class for more variable signals, such as a sine waveform, or
// a sawtooth wave for example.
// =======================================================================
//

#ifndef COURSE_3_PERIODICSIGNAL_H
#define COURSE_3_PERIODICSIGNAL_H

#include "Signal.h"

namespace Project2 {
    class PeriodicSignal :public Signal {
    public:
// [ Constructors / Destructors ] ======================================================= [ Constructors / Destructors ]
        PeriodicSignal(double voltageOffset, const Time &timeOffset, double minVoltage, double maxVoltage, Time period);

    protected:
// [ Accessors ] ========================================================================================= [ Accessors ]

        [[nodiscard]] auto getMinVoltage() const -> double;
        [[nodiscard]] auto getMaxVoltage() const -> double;
        [[nodiscard]] auto getPeriod() const -> Time;

    private:
        double minVoltage;
        double maxVoltage;
        Time period;

    };
} // namespace Project2

#endif //COURSE_3_PERIODICSIGNAL_H
