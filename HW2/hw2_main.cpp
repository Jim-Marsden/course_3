//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 9/26/2021
// https://Jim-Marsden/course_3
// =====================================================================
// hw2_main.cpp Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 11.0
// Tests the HW2/Date class.
// =====================================================================
//
#include "Date.h"
void print_date(int month, int day, int year){
    JimMarsden::Date(month, day, year).display();
}

void print_date(){
    JimMarsden::Date().display();
}

int main(){
    print_date(1, 2, 1990); // Should be fine
    print_date(2, 29, 1990); // Not a leap year - date too large
    print_date(2, 29, 2000); // is a leap year - date should be fine

    print_date(2, 1, 0000); // invalid year - is 0
    print_date(2, 1, -1990); // invalid year - is under 0

    print_date(0, 1, 2000); // invalid month - under 1
    print_date(13, 1, 1990); // invalid month - over 12

    print_date(); // Default constructed date. (Should be today's date)
    return 0;
}
