//
// Created by james on 10/29/2021.
//

#ifndef COURSE_3_SIGNAL_H
#define COURSE_3_SIGNAL_H


#include "Time.h"
namespace Project2 {
    class Signal {
    public:

        Signal(Time timeOffset, double voltageOffset);

        Signal() = delete;

        Signal(Signal const &) = default;

        Signal(Signal &&) = default;

        virtual ~Signal() = default;

        [[nodiscard]] virtual double getVoltageAtTime(Time const & t) const = 0;


    protected:
        [[nodiscard]] double getVoltageOffset() const;

        [[nodiscard]] Time getTimeOffset() const;

    private:
        double voltageOffset;
        Time timeOffset;

    };

} // namespace Project2
#endif //COURSE_3_SIGNAL_H
