//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// ConstantSignal.h - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// Implements the virtual Signal object and implements a constant
// ConstantSignal::getVoltageAtTime to return a constant voltage based on
// the offset
// =======================================================================
//


#ifndef COURSE_3_CONSTANTSIGNAL_H
#define COURSE_3_CONSTANTSIGNAL_H


#include "Signal.h"

namespace Project2 {
    class ConstantSignal : public Signal {
    public:
        ConstantSignal(  double voltageOffset, Time timeOffset);
        [[nodiscard]] double getVoltageAtTime(Time const & time) const override;

    };

 } // namespace Project2
#endif //COURSE_3_CONSTANTSIGNAL_H
