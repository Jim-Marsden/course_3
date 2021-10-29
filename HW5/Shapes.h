//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/22/2021
// https://Jim-Marsden/course_3
// =====================================================================
// Shapes.h - Tested on the following compilers in C++17 standard
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

#ifndef JIMMARSDEN_COURSE_3_SHAPES_H
#define JIMMARSDEN_COURSE_3_SHAPES_H

namespace JimMarsden {
    class Shape {
    public:
        virtual void display() const = 0; // Should only sanely display the type of shape, and reasonable measurements.
        virtual ~Shape() = default;
    };

    class TwoDimensionalShape : public Shape {
    public:
        [[nodiscard]] virtual double getArea() const = 0; // Gets the area of the shape. e.g., result = πr²
    };

    class ThreeDimensionalShape : public Shape {
    public:
        [[nodiscard]] virtual double getSurfaceArea() const = 0; // Gets the area of the shape, not volume.

        [[nodiscard]] virtual double getVolume() const = 0; // Get the volume of the shape, that is shape appropriate.
    };

    class Circle : public TwoDimensionalShape {
    public:
        ~Circle() override = default;

        Circle() = delete;

        Circle(Circle const &) = default;

        Circle(Circle &&) = default;

        Circle &operator=(Circle const &) = default;

        explicit Circle(double radius); // only assigns to radius

        void display() const override; // Displays Area of this shape.

        [[nodiscard]] double getArea() const override; // returns πr²


    private:
        double radius;
    };

    class Square : public TwoDimensionalShape {
    public:
        virtual ~Square()  = default;

        Square() = delete;

        Square(Square const &) = default;

        Square(Square &&) = default;

        Square &operator=(Square const &) = default;

        explicit Square(double lengthOfSide); // Only assigns to lengthOfSide.

        void display() const override; // Displays the area of the shape.

        [[nodiscard]] double getArea() const override; // returns lengthOfSides * lengthOfSides.

    private:
        double lengthOfSide;

    };

    class Sphere : public ThreeDimensionalShape {
    public:
        virtual ~Sphere() = default;

        Sphere() = delete;

        Sphere(Sphere const &) = default;

        Sphere(Sphere &&) = default;

        Sphere &operator=(Sphere const &) = default;

        explicit Sphere(double radius); // Only assigns to radius

        void display() const override; // Displays the SIZE, and volume of the cube.

        [[nodiscard]] double getSurfaceArea() const override; // returns 4 * pi *radius^2

        [[nodiscard]] double getVolume() const override; // returns (4/3)3πr^3

    private:
        double radius;
    };

    class Cube : public ThreeDimensionalShape {
    public:
        ~Cube() override = default;
        Cube() = delete;
        Cube(Cube const &) = default;
        Cube(Cube &&) = default;
        Cube& operator=(Cube const &) = default;
        explicit Cube(double lengthOfSide);

        void display() const override; // Displays the SIZE, and volume of the cube.

        [[nodiscard]] double getSurfaceArea() const override; // returns 6a^2

        [[nodiscard]] double getVolume() const override; // returns lengthOfSides^3

    private:
        double lengthOfSide;
    };
} // namespace JimMarsden

#endif //JIMMARSDEN_COURSE_3_SHAPES_H
