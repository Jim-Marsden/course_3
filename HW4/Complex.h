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

#ifndef COURSE_3_COMPLEX_H
#define COURSE_3_COMPLEX_H

#include <ostream> // for std::ostream
#include <istream>
namespace JimMarsden {

    class Complex {
    public:

        // [Constructors]================================================================================[Constructors]
        constexpr Complex() = default; // Default constructor.

        ~Complex() = default; // Default deconstructor

        constexpr Complex(Complex const &) = default; // Default copy constructor.

        constexpr Complex(Complex &&) = default; // Default move constructor.



        // [Operators]======================================================================================[Operators]
        // if the member operators were to be made constexpr the definition would have to be put in the header
        // file otherwise the definition would not be found at link time.

        constexpr Complex &operator=(Complex const &) = default; // Default copy assignment operator.

        constexpr Complex &operator=(Complex &&) = default; // Default move assignment operator.

        // Stream insertion operator. Should output {real}+{imaginary}i e.g., 3+3i
        friend std::ostream &operator<<(std::ostream &, const Complex &) noexcept;

        // Stream extraction operator. Expects {double}+{double}i (e.g., 3+3i) the sign and 'i'
        friend std::istream &operator>>(std::istream &, Complex &) noexcept;

        // Returns true if this->real == operand.real and this->imaginary == operand.imaginary.
        bool operator==(Complex const &) const noexcept;

        // Returns true if this->real != operand.real or this->imaginary != operand.imaginary.
        bool operator!=(Complex const &) const noexcept; // Complex inequality operator


        // Adds *this + operand and returns a copy with the new value;
        Complex operator+(Complex const &) const noexcept;

        // Adds *this + operand and returns a copy with the new value;
        Complex operator-(Complex const &) const noexcept;

        // [Utilities]======================================================================================[Utilities]
        // [Accessors/Mutators]====================================================================[Accessors/Mutators]
        // [Statics]==========================================================================================[Statics]
    private:
        // real and imaginary are the two parts of the complex number, e.g., 3+3i
        double real{}, imaginary{}; // default initializing them (to 0) thus allowing constexpr default constructor
    };
} // namespace JimMarsden

#endif //COURSE_3_COMPLEX_H
