//
// Created by james on 10/29/2021.
//

#include "Time.h"

Time::Time(unsigned int hours, unsigned int minutes, unsigned int seconds): seconds{(hours * 3600) + (minutes + 60) + seconds)} {

}

Time const &Time::operator+=(const Time & T) {
    seconds += T.seconds;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Time &) {
    return (os << T.seconds);
}
