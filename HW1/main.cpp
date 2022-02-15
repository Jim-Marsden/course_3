//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 9/26/2021
// =====================================================================
// main.cpp Tested on Linux on Clang 12 and g++ 11.1.0 built with C++17
// This file serves as a test for the Date library.
// https://Jim-Marsden/course_3
// =====================================================================
//
#include "Date.hpp"
#include <iostream>

int main()
{
    const auto overflow_month{jsl::date_constants::month_max+1};
    const auto underflow_month{jsl::date_constants::month_min-1};

    auto test_month{6}, test_day{4}, test_year{2011};
    jsl::Date date(test_month, test_day, test_year);
    date.display();

    // Check for months under minimum
    std::cout << "Checking for months under the. correct range.\n";
    for (auto i{-jsl::date_constants::month_max}; i<=underflow_month; ++i) {
        date.setMonth(i);
        if (date.getMonth()!=jsl::date_constants::month_min)
            std::cerr << "getMonth is not handling invalid months correctly.\n";
    }

    // Check for months in the correct range.
    std::cout << "Checking for months in the correct range.\n";
    for (auto i{jsl::date_constants::month_min}; i<=jsl::date_constants::month_max; ++i) {
        date.setMonth(i);
        if (date.getMonth()!=i)
            std::cerr << "getMonth is not handling valid months correctly.\n";
    }

    // Check for months over maximum.
    std::cout << "Checking for months over the correct range.\n";
    for (auto i{overflow_month}; i<=overflow_month+overflow_month; ++i) {
        date.setMonth(i);
        if (date.getMonth()!=jsl::date_constants::month_min)
            std::cerr << "getMonth is not handling invalid months correctly.\n";
    }

    // Check getters and setter for day.
    date.setDay(test_day-1);
    if (date.getDay()!=test_day-1)
        std::cerr << "Year not assigning correctly.";

    // Check getters and setter for year.
    date.setYear(test_year+1);
    if (date.getYear()!=test_year+1)
        std::cerr << "Year not assigning correctly.";

    // Final date should be 1/3/2012. The month was an invalid date, so it should be 1, I've taken away one from four,
    // and added one to 2011.
    std::cout << "The final date should be \"1/3/2012\".\n";
    date.display();

    return 0;
}
