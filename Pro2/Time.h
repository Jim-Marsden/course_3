//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// Time.h - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// A class to manage time (as an unsigned long int) so it can be logged
// and recorded. It's constructor takes 3 integers, Hours, Minutes,
// Seconds. It correctly converts them into seconds.
// =======================================================================
//

#ifndef COURSE_3_TIME_H
#define COURSE_3_TIME_H

#include <ostream>

namespace Project2 {
    class Time {
    public:
// [ Constructors / Destructors ] ======================================================= [ Constructors / Destructors ]
        // Converts hours, and minutes to seconds and applies it to Time::seconds
        Time(unsigned hours, unsigned minutes, unsigned seconds);

        Time() = delete;

        Time(Time const &) = default;

        Time(Time &&) = default;

        ~Time() = default;
// [ Operators ] ========================================================================================= [ Operators ]
        auto operator=(Time const &) -> Time & = default;

        auto operator+=(Time const &) -> Time const & ; // Adds seconds together.

        explicit operator double() const; // converts getTotalTimeAsSeconds to double, and returns that.

        friend std::ostream &operator<<(std::ostream &os, Time const &);
// [ Accessors ] ========================================================================================= [ Accessors ]
        [[nodiscard]] auto getTotalTimeAsSeconds()  const -> unsigned long long; // Gets seconds.

    private:
        unsigned long long seconds;

    };
} // namespace Project2

#endif //COURSE_3_TIME_H
