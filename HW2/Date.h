//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 9/26/2021
// https://Jim-Marsden/course_3
// =====================================================================
// Date.h Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 11.0
//
// A class to hold a date, with light validation.
// The default constructor will always the current date valid
// =====================================================================
//
#ifndef JIMMARSDEN_DATE_H
#define JIMMARSDEN_DATE_H

namespace JimMarsden {
    namespace DateConsts {
        constexpr auto month_min{1};
        constexpr auto month_max{12};

        constexpr auto year_min{0};
    }
    class Date {
    public:
        // Constructors

        Date(int month, int day, int year);

        // Sets month, day, year based on system time
        Date();

        ~Date() = default;

        Date(Date const &) = default; //copy

        Date(Date &&) = default; // move

        //Mutators
        [[nodiscard]] inline int getMonth() const;

        [[nodiscard]] inline int getDay() const;

        [[nodiscard]] inline int getYear() const;

        //Utility
        void display() const;

    protected:

        /*
         * It was suggested in Lesson 2 that we use setters as a best practice.
         *
         * The following mutators are protected as they are not stated on the UML
         * They are not inlined as to avoid needing to have any includes such as iostream
         *
         * They report an error via STDERR
         * They do not change the parameter's value, only report issues with invalid ranges.
         *
         */
        void setYear(int year); // Valid range: year > 0
        void setDay(int day); // Valid range: 28..31 (depending on Date::month and Date::year)
        void setMonth(int month); // Valid range: 1..12

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
    return year;
}


#endif //JIMARSDEN_DATE_H
