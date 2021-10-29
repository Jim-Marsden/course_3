//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/22/2021
// https://Jim-Marsden/course_3
// =====================================================================
// Shapes.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 11.0
//
// Definitions for virtual/Abstract classes :
// Shape, TwoDimensionalShape, and ThreeDimensionalShape
//
// Definition and inheriting form:
// Circle <- TwoDimensionalShape <- Shape
// Square <- TwoDimensionalShape <- Shape
//
// Sphere <- ThreeDimensionalShape <- Shape
// Cube <- ThreeDimensionalShape <- Shape
// =====================================================================
//

#include "Shapes.h"

#include <iostream>
#include <cmath>


namespace shapes_cpp_globals { static constexpr auto PI{3.14159265359}; }

JimMarsden::Circle::Circle(double radius) : radius{radius} {}

void JimMarsden::Circle::display() const {
    std::cout << "Circle with radius: " << radius
              << " has area " << getArea() << " \n";
}

double JimMarsden::Circle::getArea() const {
    // π r²
    return shapes_cpp_globals::PI * std::pow(radius, 2);
}

JimMarsden::Square::Square(double lengthOfSide)
        : lengthOfSide{lengthOfSide} {}

void JimMarsden::Square::display() const {
    std::cout << "Square with length of side  " << 3
              << " has area " << getArea() << '\n';
}

double JimMarsden::Square::getArea() const {
    return lengthOfSide * lengthOfSide;
}

JimMarsden::Sphere::Sphere(double radius) : radius{radius} {}

void JimMarsden::Sphere::display() const {
    std::cout << "Sphere with radius " << radius << " has surface area "
              << getSurfaceArea() << " and volume " << getVolume() << '\n';
}

double JimMarsden::Sphere::getSurfaceArea() const {
    // 4 * pi *radius^2
    return (shapes_cpp_globals::PI * 4) * std::pow(radius, 2);
}

double JimMarsden::Sphere::getVolume() const {

    //(4/3)3πr^3 = Volume
    using shapes_cpp_globals::PI;
    static constexpr auto three_per_four{4.0 / 3.0};

    return three_per_four * PI * std::pow(radius, 3);
}

JimMarsden::Cube::Cube(double lengthOfSide) : lengthOfSide{lengthOfSide} {}

void JimMarsden::Cube::display() const {
    std::cout << "Cube with length of side " << lengthOfSide << " has surface area " << getSurfaceArea()
              << " and volume " << getVolume();
}

double JimMarsden::Cube::getSurfaceArea() const {
    // 6a^2 = number_of_sides*a^2
    static constexpr auto number_of_sides{6.0};
    return number_of_sides * std::pow(lengthOfSide, 2);
}

double JimMarsden::Cube::getVolume() const {
    // a^3
    return pow(lengthOfSide, 3);
}
