//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 9/26/2021
// =====================================================================
// Date.hpp Tested on Linux on Clang 12 and g++ 11.1.0 built with C++17
// Takes a month, day, year, validates the month and can print it in a
// Month, Day, Year format. E.g. (6/4/2011)
// https://Jim-Marsden/course_3
// =====================================================================
//

#include "Date.hpp"
#include <iostream>

jsl::Date::Date(int month_in, int day_in, int year_in)
{
    // to validate private member data in the same way as the setters, and ensure the same issues would be raised.
    setMonth(month_in);
    setDay(day_in);
    setYear(year_in);
}

void jsl::Date::setMonth(int month_in) noexcept
{
    namespace date_consts = jsl::date_constants; // save on clutter for readability.

    // Make sure Date::month is the same correct numeric range
    if (month_in < date_consts::month_min || month_in > date_consts::month_max) {
        month = date_consts::month_min; // sets to the minimum valid date, should be 1.
        std::cerr << "Valid months are " << date_consts::month_min << ".." << date_consts::month_max << ".\n";
    }
    else month = month_in; // if valid, we just simply assign month_in to month.
}

int jsl::Date::getMonth() const noexcept
{
    return month;
}

void jsl::Date::setDay(int day_in) noexcept
{
    // setting Date::day to day_in without validations.
    day = day_in;
}

int jsl::Date::getDay() const noexcept
{
    return day;
}

void jsl::Date::setYear(int year_in) noexcept
{
    // setting Date::year to year_in without validations.
    year = year_in;
}

int jsl::Date::getYear() const noexcept
{
    return year;
}

void jsl::Date::display() const noexcept
{
    // outputting the private member data through cout, and the data.
    std::cout << month << '/' << day << '/' << year << '\n';
}
