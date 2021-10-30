//
// Created by james on 10/29/2021.
//

#include <iostream>
#include <chrono>
#include "Time.h"

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
        constexpr auto seconds_per_hour{3600};
        auto hours = (time.seconds / 3600);

        auto minutes = (time.seconds - (3600 * hours)) / 60;

        auto seconds = (time.seconds - (3600 * hours) - (minutes * 60));

        os << hours << "h:" << minutes << "m:" << seconds << 's';
    }

    return os;
}
