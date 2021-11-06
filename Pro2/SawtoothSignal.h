//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// Sawtooth.h - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Implements the abstract class -- PeriodicSignal. Generates a
// Triangle waves by implementing PeriodicSignal::getVoltageAtTime
// =======================================================================
//

#ifndef COURSE_3_SAWTOOTHSIGNAL_H
#define COURSE_3_SAWTOOTHSIGNAL_H

#include "PeriodicSignal.h"

namespace Project2 {
    class SawtoothSignal : public PeriodicSignal{
    public:
// [ Constructors / Destructors ] ======================================================= [ Constructors / Destructors ]
        SawtoothSignal(double voltageOffset, const Time &timeOffset, double minVoltage, double maxVoltage,
                       const Time &period);
// [ Accessors ] ========================================================================================= [ Accessors ]
        [[nodiscard]] auto getVoltageAtTime(Time const & t) const  -> double override;
    };
} // namespace Project2

#endif //COURSE_3_SAWTOOTHSIGNAL_H
