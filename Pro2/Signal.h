//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// Signal - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// The most basal abstract class that handles the most basal form of
// signaling.
// =======================================================================
//


#ifndef COURSE_3_SIGNAL_H
#define COURSE_3_SIGNAL_H


#include "Time.h"
namespace Project2 {
    class Signal {
    public:
// [ Constructors / Destructors ] ======================================================= [ Constructors / Destructors ]

        Signal(Time timeOffset, double voltageOffset);

        Signal() = delete;

        Signal(Signal const &) = default;

        Signal(Signal &&) = default;

        virtual ~Signal() = default;

// [ Utilities ] ========================================================================================= [ Utilities ]
        [[nodiscard]] virtual double getVoltageAtTime(Time const & t) const = 0;

    protected:
        [[nodiscard]] auto getVoltageOffset() const -> double ;

        [[nodiscard]] auto getTimeOffset() const -> Time;
// [ Accessors ] ========================================================================================= [ Accessors ]

    private:
        double voltageOffset;
        Time timeOffset;

    };

} // namespace Project2
#endif //COURSE_3_SIGNAL_H
