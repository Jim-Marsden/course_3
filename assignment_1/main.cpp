//
// Created by james on 9/24/2021.
//
#include "Date.hpp"

int main() {
    Date date1(6, 4, 11);
    date1.display();

    Date date2(13, 4, 11);
    date2.display();

    Date date3(0, 4, 11);
    date3.display();

    date3.setMonth(999);
    date3.display();

    date3.setMonth(-999);
    date3.display();

}