//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/17/2021
// https://Jim-Marsden/course_3
// =====================================================================
// Complex.h - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 11.0
//
// A class for managing complex numbers. It has two floats, one for
// real, and one for the imaginary. With stream insertion, +, -, and, =.
// The << formats it in a reasonable way you would expect for
// complex numbers.
// =====================================================================
//
#include "Complex.h"

std::istream &JimMarsden::operator>>(std::istream & in, JimMarsden::Complex &complex) noexcept {
    char i = '+'; // just a spacer for the stream. It could be anything, and is discarded.
    in >> complex.real;
    in >> i ; // one byte buffer.
    in >> complex.imaginary;
    return in;
}

std::ostream &JimMarsden::operator<<(std::ostream & out, const JimMarsden::Complex & complex) noexcept {
    out << complex.real << '+'<< complex.imaginary << 'i';
    return out;
}

bool JimMarsden::Complex::operator==(const JimMarsden::Complex &op1) const noexcept {
    return op1.imaginary == imaginary && op1.real == real;
}

bool JimMarsden::Complex::operator!=(const JimMarsden::Complex &op1) const noexcept {
    // should be as 'return op1.real != this->real || this->imaginary != op1.imaginary;
    return !(op1 == *this);
}

JimMarsden::Complex JimMarsden::Complex::operator+(const JimMarsden::Complex &op1) const noexcept {
    Complex result; // Returns a temporary.
    result.real = real + op1.real; // result = this + that
    result.imaginary = imaginary + op1.imaginary;
    return result;
}

JimMarsden::Complex JimMarsden::Complex::operator-(const JimMarsden::Complex & op1) const noexcept {
    Complex result; // Returns a temporary.
    result.real = real - op1.real;
    result.imaginary = imaginary - op1.imaginary;
    return result;
}
