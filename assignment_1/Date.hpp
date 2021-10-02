//
// Created by james on 9/24/2021.
//

#ifndef COURSE_3_DATE_H
#define COURSE_3_DATE_H

class Date {
    int day, month, year;
public:
    Date() = delete;

    Date(int month, int day, int year) noexcept;

    Date(Date const &d) = default;

    Date(Date &&date) = default;

    Date &operator=(Date const &) = default;

    void setMonth(int month);

    [[nodiscard]] int getMonth() const noexcept;

    void setDay(int day);

    [[nodiscard]] int getDay() const noexcept;

    void setYear(int year);

    [[nodiscard]] int getYear() const noexcept;

    void display() const noexcept;
};

#endif //COURSE_3_DATE_H
