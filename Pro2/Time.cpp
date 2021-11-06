//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/29/2021
// https://Github.com/Jim-Marsden/course_3
// =======================================================================
// Time.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 10.2
//
// A class to manage time (as an unsigned long int) so it can be logged
// and recorded. It's constructor takes 3 integers, Hours, Minutes,
// Seconds. It correctly converts them into seconds.
// =======================================================================
//

#include <iostream>
#include <chrono>
#include "Time.h"

/// Maybe it would be better to do : using dhours = std::chrono::duration<double,  3600> over using math. That would may be less error prone?
Project2::Time::Time(unsigned int hours, unsigned int minutes, unsigned int seconds): seconds{(hours * 3600) + (minutes * 60) + seconds} {}

Project2::Time const &Project2::Time::operator+=(const Project2::Time & T) {
    seconds += T.seconds;
    return *this;
}

auto Project2::Time::getTotalTimeAsSeconds() const -> unsigned long long{
    return seconds;
}

std::ostream &Project2::operator<<(std::ostream &os, const Project2::Time & time) {

    if(time.seconds == 0) os << "0h:0m:0s";
    else {
        using std::chrono::duration_cast; // Using Chrono enables me to not have to use any numbers, and avoid getting my math wrong.
        std::chrono::seconds time_seconds(time.seconds);

        auto hours = duration_cast<std::chrono::hours>(time_seconds);

        auto minutes = duration_cast<std::chrono::minutes>(time_seconds - hours); // Minutes w/ hours deducted

        auto seconds = duration_cast<std::chrono::seconds>(time_seconds - minutes - hours); // remaining seconds after minutes and hours

        os << hours.count() << "h:" << minutes.count() << "m:" << seconds.count() << 's';
    }

    return os;
}

Project2::Time::operator double() const {
    return static_cast<double>(getTotalTimeAsSeconds());
}
