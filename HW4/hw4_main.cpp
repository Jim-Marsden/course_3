//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/17/2021
// https://Jim-Marsden/course_3
// =====================================================================
// hw4.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 11.0
//
// Run various tests for Complex.h/Complex.cpp
// =====================================================================
//
#include <iostream>
#include <sstream>

#include "Complex.h"

#include <map>
#include <string>

/*
 * Has an ordered map of tests. It prints to STDOUT if the test has passed, e.g.,
 * 'operator == expected true: passed.' or 'operator == expected true: failed.'
 *
 * Currently tests the following:
 *
 * 1) Operator !=
 * 2) Operator +
 * 3) Operator -
 * 4) Operator ==
 * 5) Operator << (Stream Insertion)
 * 6) Operator >> (Stream Extraction)
 */
void do_tests() {

    std::map<std::string, bool(*)()> tests;

    tests["operator + (0+0i + 0+0i)"] = []() {
        auto comp = JimMarsden::Complex() + JimMarsden::Complex();
        if (comp == JimMarsden::Complex())
            return true;
        return false;
    };

    tests["operator + (0+0i + 3+3i)"] = []() {
        JimMarsden::Complex comp1, comp2;
        std::stringstream ss1;
        ss1 << 3.0 << '+' << 3 << 'i';
        ss1 >> comp1;
        auto comp3 = comp1 + comp2;
        if (comp1 != comp2 && comp1 == comp3)
            return true;
        return false;
    };

    tests["operator - (0+0i - 0+0i)"] = []() {
        auto comp = JimMarsden::Complex() - JimMarsden::Complex();
        if (comp == JimMarsden::Complex())
            return true;
        return false;
    };

    tests["operator - (0+0i - 3+3i)"] = []() {
        JimMarsden::Complex comp1, comp2;
        std::stringstream ss1;
        ss1 << 3.0 << '+' << 3 << 'i';
        ss1 >> comp1;
        auto comp3 = comp2 -  comp1;
        if (comp1 != comp2 && comp1 != comp3)
            return true;
        return false;
    };

    tests["printing from ostream"] = []() {
        std::cout << JimMarsden::Complex() << ' ';
        return true;
    };
    tests["printing from stringstream"] = []() {
        std::stringstream ss;
        ss << JimMarsden::Complex();
        return !ss.str().empty();
    };

    tests["read from stringstream"] = []() {
        std::stringstream ss1, ss2;
        JimMarsden::Complex comp;
        ss1 << 3.0 << '+' << 3 << 'i';
        ss1 >> comp;
        ss2 << 3.0 << '+' << 3 << 'i';
        return ss1.str() == ss2.str();
    };

    tests["operator != expected true"] = []() { return !(JimMarsden::Complex() != JimMarsden::Complex()); };
    tests["operator != expected false, left"] = []() {
        std::stringstream ss;
        JimMarsden::Complex complex;
        ss << 3 << '+' << 3 << 'i';
        ss >> complex;
        return (complex != JimMarsden::Complex());
    };

    tests["operator == expected false, right"] = []() {
        std::stringstream ss;
        JimMarsden::Complex complex;
        ss << 3 << '+' << 3 << 'i';
        ss >> complex;
        return (JimMarsden::Complex() != complex);
    };


    tests["operator == expected true"] = []() { return JimMarsden::Complex() == JimMarsden::Complex(); };
    tests["operator == expected false, left"] = []() {
        std::stringstream ss;
        JimMarsden::Complex complex;
        ss << 3 << '+' << 3 << 'i';
        ss >> complex;
        return !(complex == JimMarsden::Complex());
    };

    tests["operator == expected false, right"] = []() {
        std::stringstream ss;
        JimMarsden::Complex complex;
        ss << 3 << '+' << 3 << 'i';
        ss >> complex;
        return !(JimMarsden::Complex() == complex);
    };
    for (auto[test_name, test_function]: tests) {
        std::cout << test_name << ": " << (test_function() ? "passed." : "failed.") << '\n';
    }
}

int main(){
    do_tests();
    return 0;
}

