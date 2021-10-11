//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 9/26/2021
// https://Jim-Marsden/course_3
// =====================================================================
// Date.cpp Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 11.0
//
// A class to hold a date, with light validation.
// The default constructor will always the current date valid
// =====================================================================
//
#include "Date.h"

#include <chrono>
#include <iostream>

static int days_in_months(int month, int year);


/*
 * Returns the appropriate number of days in the month. E.g., 31 in January
 * Also checks for leap years.
 *
 * Prints to STDERR if the months isn't 1..12
 */
int days_in_months(int month, int year) {

    switch (month) {
        // 31 day months
        case 1: // January
        case 3: // March
        case 5: // May
        case 7: // July
        case 8: // August
        case 10: // October
        case 12: // December
            return 31;

        //30 day months
        case 4: // April
        case 6: // June
        case 9: // September
        case 11: // November
            return 30;
        //feb
        case 2:
            if (year % 400 != 0 && year % 4 == 0 || year % 100 == 0) {
                return 29;
            }
            return 28;

        default:
            return 0;
            std::cerr << "Possible invalid month: " << month << '\n';
            break;
    }
}


JimMarsden::Date::Date(int month, int day, int year) {
    setMonth(month);
    setYear(year);

    // Date::setDay() is based on on the year and month, it has to be set last.
    setDay(day);
}

JimMarsden::Date::Date() {
    namespace chrono = std::chrono;
    auto const current_time = chrono::system_clock::now(); // gets the current time
    auto const current_time_t = chrono::system_clock::to_time_t(current_time); // converts to time_t
    tm local_tm = *localtime(&current_time_t); // gets time struct from time_t

    // We store months 1..12, local_tm stores time from 0..11
    this->month = local_tm.tm_mon + 1;

    this->day = local_tm.tm_mday;

    // local_tm stores years since from 1900, e.g., 121 + 1900 = 2021
    this->year = local_tm.tm_year + 1900;

}


void JimMarsden::Date::display() const {
    std::cout << this->month << '/' << this->day << '/' << this->year << '\n';
}

void JimMarsden::Date::setMonth(int month) {
    if (month < JimMarsden::DateConsts::month_min)
        std::cerr << "Moth is smaller than " << JimMarsden::DateConsts::month_min << ".\n";
    if (month > JimMarsden::DateConsts::month_max)
        std::cerr << "Moth is greater than " << JimMarsden::DateConsts::month_max << ".\n";
    this->month = month;
}


void JimMarsden::Date::setDay(int day) {
    const auto max_day = ::days_in_months(month, year);
    if (max_day < day) {
        // if we want to handle issues with large days, we can put it here.
        std::cerr << "Day is too large, " << max_day << " max.\n";
    }
    if (day <= 0) {
        std::cerr << "Day is too small, 1 is minimum.\n";
    }
    this->day = day;
}

void JimMarsden::Date::setYear(int year) {
    if (year < JimMarsden::DateConsts::year_min) {
        // if we want to handle an invalid year
        std::cerr << "Year is below minimum value: " << JimMarsden::DateConsts::year_min << '\n';
    }

    this->year = year;
}
