//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// SineSignal.h - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Override from PeriodicSignal to allow for a sine waveform.
// =======================================================================
//

#ifndef COURSE_3_SINESIGNAL_H
#define COURSE_3_SINESIGNAL_H


#include "PeriodicSignal.h"

namespace Project2 {
    class SineSignal : public PeriodicSignal {
    public:
// [ Constructors / Destructors ] ======================================================= [ Constructors / Destructors ]
        SineSignal(double voltageOffset, const Time &timeOffset, double minVoltage, double maxVoltage,
                   const Time &period);
// [ Accessors ] ========================================================================================= [ Accessors ]
        //Generates a sinewave.
        [[nodiscard]] auto getVoltageAtTime(Time const & t) const -> double override;
    };
} // namespace Project2

#endif //COURSE_3_SINESIGNAL_H
