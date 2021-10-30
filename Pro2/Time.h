//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_TIME_H
#define COURSE_3_TIME_H

#include <ostream>

namespace Project2 {
    class Time {
    public:
        Time(unsigned hours, unsigned minutes, unsigned seconds);

        Time() = delete;

        Time(Time const &) = default;

        Time(Time &&) = default;

        ~Time() = default;

        auto operator=(Time const &) -> Time & = default;

        auto operator+=(Time const &) -> Time const & ;

        friend std::ostream &operator<<(std::ostream &os, Time const &);

        [[nodiscard]] auto getTotalTimeAsSeconds()  const -> unsigned long long;

    private:
        unsigned long long seconds;

    };
} // namespace Project2

#endif //COURSE_3_TIME_H
