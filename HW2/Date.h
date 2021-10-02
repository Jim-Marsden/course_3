//
// Created by james on 10/1/2021.
//

#ifndef JIMMARSDEN_DATE_H
#define JIMMARSDEN_DATE_H

namespace JimMarsden {
    namespace DateConsts{
        constexpr auto month_min{1};
        constexpr auto month_max{12};

        constexpr auto year_min{0};
    }
    class Date {
    public:
        // Constructors

        Date(int month, int day, int year);

        Date();

        ~Date() = default;

        Date(Date const &) = default;

        Date(Date &&) = default;

        //Mutators
        [[nodiscard]] inline int getMonth() const;

        /*
         * not inlined so we don't have to expose iostream
         * Validates the range of months, without mutating the value
         * Valid months 1..12
         */
        void setMonth(int month); // not inlined so we don't have to expose iostream

        [[nodiscard]] inline int getDay() const;
        /*
         * not inlined so we don't have to expose iostream
         * Validates the day, insuring that whatever mothn it is, has more days than the month does, handling for
         * leap years
         *
         * Doesn't mutate the input, accepts it.
         */
        void setDay(int day); // not inlined so we don't have to expose iostream

        [[nodiscard]] inline int getYear() const;
        void setYear(int year); // not inlined so we don't have to expose iostream

        //Utility
        void display() const;

    private:
        int month, day, year;
    };

}

int JimMarsden::Date::getMonth() const {
    return month;
}

int JimMarsden::Date::getDay() const {
    return day;
}

int JimMarsden::Date::getYear() const {
    return  year;
}


#endif //JIMARSDEN_DATE_H
