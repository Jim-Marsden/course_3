//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_TIME_H
#define COURSE_3_TIME_H

#include <ostream>
class Time {
public:
    Time(unsigned hours, unsigned minutes, unsigned seconds);

    Time() = delete;
    Time(Time const &) = default;
    Time(Time &&) = default;
    ~Time() = default;

    Time & operator=(Time const &) = default;
    Time const & operator +=(Time const &);
    friend std::ostream & operator<<(std::ostream & os, Time const &);

private:
    unsigned long long seconds;

};


#endif //COURSE_3_TIME_H
