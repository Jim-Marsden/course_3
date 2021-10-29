//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/22/2021
// https://Jim-Marsden/course_3
// =====================================================================
// hw5.cpp - Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 11.0
//
// "Testing" shape's dynamic polymorphism, and safely cleans up memory.
// =====================================================================
//

#include "Shapes.h"

#include <array>
#include <iostream>
int main(){

    // Makes a std::array of four shapes, and initializes them to nullptr.
    std::array<JimMarsden::Shape*, 4> shapes{};

    // Ensure I constructed Shapes correctly. (Not that it particularly matters, it's getting assigned next).
    for(auto const & shapes_element : shapes)
        if(shapes_element != nullptr) throw std::runtime_error("my bad");

    shapes[0] = new JimMarsden::Circle(2);
    //Circle with radius 2 has area 12.5664
    shapes[1] = new JimMarsden::Square(3);
    //Square with length of side 3 has area 9
    shapes[2] = new JimMarsden::Sphere(4);
    //Sphere with radius 4 has surface area 201.062 and volume 268.083
    shapes[3] = new JimMarsden::Cube(5);//Cube with length of side 5 has surface area 150 and volume 125

    // Displays then frees all elements in the shapes array.
    // Mostly to test that everything is implemented correctly.
    for(auto & shape_element : shapes){
        shape_element->display();
        delete shape_element;
    }

}