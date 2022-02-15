//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 11/05/2021
// =====================================================================
// StringUtility.h Tested on Linux on Clang 12 and g++ 11.1.0 built with C++17
// https://Github.com/Jim-Marsden/course_3
//
// A class with 4 member functions: Join, Reverse Combine, and LeftPad
// =====================================================================

#ifndef COURSE_3_STRINGUTILITY_H
#define COURSE_3_STRINGUTILITY_H

#include <string>
#include <vector>

namespace JimMarsden {
    using str_vec = std::vector<std::string>;

    class StringUtility { // I would strongly suggest making this a set of free functions over a class or static cast.
        // This would remove the need of the "this" pointer.
    public:

        // Joins a vector of strings into a single string with a delimiter.
        [[nodiscard]] auto join(const std::vector<std::string>& strings, char delimiter) const -> std::string;

        // reverses a vector of strings
        [[nodiscard]] auto reverse(const str_vec& strings) const -> str_vec;

        // Merges and creates all permutations based on left and right. (Returns a sorted vector)
        [[nodiscard]] auto combine(const str_vec& left, const str_vec& right) const -> str_vec;

        // if the size of an element is less than 3, add a pad until it becomes 3.
        [[nodiscard]] auto leftPad(const str_vec& strings, char pad) const -> std::vector<std::string>;
    };
} // namespace JimMarsden
#endif // COURSE_3_STRINGUTILITY_H
