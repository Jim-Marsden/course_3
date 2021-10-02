//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 9/26/2021
// =====================================================================
// Date.hcp Tested on Linux on Clang 12 and g++ 11.1.0 built with C++17
// Takes a month, day, year, validates the month and can print it in a
// Month, Day, Year format. E.g. (6/4/2011)
// https://Jim-Marsden/course_3
// =====================================================================
//

#ifndef JSL_COURSE_3_DATE_H
#define JSL_COURSE_3_DATE_H

// Jim's School Library
namespace jsl {
    namespace date_constants {
        constexpr auto month_min{1}; // Would be an error if month is less than 1
        constexpr auto month_max{12}; // and greater than 12.
    }
    class Date {
        int month, day, year;
    public:

        // No specification for default constructor was stated, so I figured it wasn't intended.
        // That is to say, default constructing would be a bug.
        Date() = delete;

        // default destructor.
        ~Date() = default;

        // intended constructor, sets the private data with sane, defined values.
        Date(int month, int day, int year);

        // default copy constructor.
        Date(Date const& d) = default;

        // default move constructor.
        Date(Date&& date) = default;

        // default assignment operator.
        Date& operator=(Date const&) = default;

        // validates the month parameter is 1..12
        // sets Date::month with the month parameter.
        void setMonth(int month) noexcept;

        // Not getting the return value would be a bug.
        // Returns Date::month
        [[nodiscard]] int getMonth() const noexcept;

        // sets Date::day with the input day.
        void setDay(int day) noexcept;

        // Not getting the return value would be a bug.
        // Returns Date::day
        [[nodiscard]] int getDay() const noexcept;

        // sets Date::year with the input year.
        void setYear(int year) noexcept;

        // Not getting the return value would be a bug.
        // Returns Date::year
        [[nodiscard]] int getYear() const noexcept;

        // Displays Date::month, Date::day, and Date::year in m/d/y format, e.g. (6/4/2011)
        void display() const noexcept;
    };
}
#endif //JSL_COURSE_3_DATE_H
