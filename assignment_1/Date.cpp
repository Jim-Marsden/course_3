//
// Created by james on 9/24/2021.
//

#include "Date.hpp"
#include <iostream>

Date::Date(int month, int day, int year) noexcept {
    setDay(day);
    setMonth(month);
    setYear(year);
}

void Date::setMonth(int month) {
    if(month < 1 || month > 12){
        this->month = 1;
        std::cerr << "Month is invalid\n";
    }
    else this->month = month;
}

int Date::getMonth() const noexcept {
    return month;
}

void Date::setDay(int day) {
    this->day = day;
}

int Date::getDay() const noexcept {
    return day;
}

void Date::setYear(int year) {
    this->year = year;
}

int Date::getYear() const noexcept {
    return year;
}

void Date::display() const noexcept {
    std::cout << month << '/' << day << '/' << year << '\n';
}
