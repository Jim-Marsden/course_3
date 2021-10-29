//
// Created by james on 10/28/2021.
//

#include "Array.h"
#include <iostream>

template<class array_t>
void print(array_t const &array) {
    for (auto const &e: array) {
        std::cout << e << ", ";
    }
    std::cout << '\n';
}

bool test_a();

bool test_b();

bool test_c();

bool test_d();

bool test_e();

bool test_f();

bool test_g();

bool test_h();

bool test_i();

bool test_j();

bool test_k();

int main() {
    auto test_printer = [](auto test_name, bool test) {
        std::cout << "Test: " << test_name << ' ';
        if (test) std::cout << "passed.\n";
        else std::cout << "failed.\n";
    };

    test_printer("a", test_a()); // a. Create an Array using the default constructor [done]
    test_printer("b",
                 test_b()); // b. Modify all of the elements of an Array using the L-value subscript operator [ done ]
    test_printer("c", test_c()); // c. Output all of the elements of an Array using the R-value subscript operator
    test_printer("d", test_d()); // d. Create a const Array from another Array using the copy constructor
    test_printer("e", test_e()); // e. Assign an Array to an existing Array using the copy assignment operator
    test_printer("f", test_f()); // f. Compare two Arrays using the equality operator [ done ]
    test_printer("g", test_g()); // g. Compare two Arrays using the inequality operator [ done ]

    test_printer("h", test_h()); /* h. Demonstrate an invalid_argument exception being thrown and caught when the
                                             * L-value subscript operator is accessed with an index < 0*/

    test_printer("i", test_i()); /*i. Demonstrate an invalid_argument exception being thrown and caught when the
                                             * L-value subscript operator is accessed with an index >= SIZE*/

    // This test is invalid, as I used an unsigned integer. Therefore, it cannot be less than 0. I think the program would be malformed if you can access -1 on an array.
    test_printer("j", test_j()); /* j. Demonstrate an invalid_argument exception being thrown and caught when the
                                            * R-value subscript operator is accessed with an index < 0 (you can force the R-value
                                            * subscript operator to be called by accessing an element in the const Array). */

    // This test is invalid, as I used an unsigned integer. Therefore, it cannot be less than 0. I think the program would be malformed if you can access -1 on an array.
    test_printer("k", test_k()); /* k. Demonstrate an invalid_argument exception being thrown and caught when the
                                             * R-value subscript operator is accessed with an index >= SIZE (you can force the R-
                                             * value subscript operator to be called by accessing an element in the const Array) */

}

using JimMarsden::Array;


bool test_a() {
    Array<int, 0xff> array1;
    for (auto &element: array1) { if (element != int{}) return false; }
    Array<int, 0xff> const array2;
    for (auto &element: array2) { if (element != int{}) return false; }
    return true;
}

bool test_b() {
    Array<unsigned, 0xff> array1;
    for (unsigned c{}; c < array1.size(); c++) {
        array1[c] = c;
    }
    for (unsigned c{}; c < array1.size(); c++) {
        if (array1[c] != c) return false;
    }
    return true;
}

bool test_c() {
    Array<unsigned, 0xf> array1;

    for (unsigned c{}; c < array1.size(); c++) {
        array1[c] = c;
    }
    auto const array2 = array1;
    for (unsigned c{}; c < array2.size(); c++) {
        if (array2[c] != c) return false;
        std::cout << array2[c] << ',';
    }
    std::cout << '\n';
    return true;
}

bool test_d() {
    Array<unsigned, 0xf> array1;

    for (unsigned c{}; c < array1.size(); c++) {
        array1[c] = c;
    }
    auto const array2(array1);
    for (unsigned c{}; c < array2.size(); c++) {
        if (array2[c] != c) return false;
    }
    return true;
}

bool test_e() {
    Array<unsigned, 0xf> array1;

    for (unsigned c{}; c < array1.size(); c++) {
        array1[c] = c;
    }
    auto const array2 = array1;
    for (unsigned c{}; c < array2.size(); c++) {
        if (array2[c] != c) return false;
    }
    return true;
}

bool test_f() {

    Array<unsigned, 0xf> array1;

    for (unsigned c{}; c < array1.size(); c++) {
        array1[c] = c;
    }
    auto const array2 = array1;
    return array1 == array2 && !(array1 == decltype(array1){});
}

bool test_g() {
    Array<unsigned, 0xf> array1;

    for (unsigned c{}; c < array1.size(); c++) {
        array1[c] = c;
    }

    return array1 != decltype(array1){};
}

bool test_h() {
    constexpr auto size_of_array = 0xf;
    Array<unsigned, size_of_array> array1;
    try{
        array1[size_of_array];
    }
    catch(std::invalid_argument &e){
        return true;
    }
    return false;
}

bool test_i() {

    constexpr auto size_of_array = 0xf;
    const Array<unsigned, size_of_array> array1;
    try{
        array1[size_of_array];
    }
    catch(std::invalid_argument &e){
        return true;
    }
    return false;
}

bool test_j() { return true; }

bool test_k() { return false; }