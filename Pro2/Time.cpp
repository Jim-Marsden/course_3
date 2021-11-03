//
// Created by james on 10/29/2021.
//

#include <iostream>
#include <chrono>
#include "Time.h"

//TODO: Use std::chrono::duration_cast<decltype(seconds), ratio> instead of math?
Project2::Time::Time(unsigned int hours, unsigned int minutes, unsigned int seconds): seconds{(hours * 3600) + (minutes * 60) + seconds} {}

Project2::Time const &Project2::Time::operator+=(const Project2::Time & T) {
    seconds += T.seconds;
    new int();
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
