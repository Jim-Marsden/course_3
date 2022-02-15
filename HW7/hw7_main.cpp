//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 11/05/2021
// =====================================================================
// main.cpp Tested on Linux on Clang 12 and g++ 11.1.0 built with C++17
// https://Github.com/Jim-Marsden/course_3
//
// Tests for StringUtilities class.
// =====================================================================

#include "StringUtility.h"
#include <iostream> // for printing

#include <map> // For unit testing
#include <functional> // For unit testing
#include <algorithm> // For std::sort


int main()
{
    using JimMarsden::StringUtility;
    using str_vec = std::vector<std::string>;
    std::map<std::string, std::function<bool()>> tests;
    StringUtility utility{};

    tests["join test"] = [&utility]() {
        str_vec str_vec1{"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};

        // Another example of every letter in the alphabet, but I like this one more.
        str_vec str_vec2{"Sphinx", "of", "black", "quartz,", "judge", "my", "vow."};
        auto fox = utility.join(str_vec1, ',');
        auto sphinx = utility.join(str_vec2, ' ');
        return (fox=="The,quick,brown,fox,jumps,over,the,lazy,dog") &&
                sphinx=="Sphinx of black quartz, judge my vow.";
    };

    tests["join empty vector"] = [&utility]() {
        str_vec empty;
        return utility.join(empty, '*').empty(); // is the same as str == "" bust faster, and arguably clearer.
    };

    tests["reverse"] = [&utility]() {
        return utility.reverse({"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"})
                ==str_vec{"dog", "lazy", "the", "over", "jumps", "fox", "brown", "quick", "The"};
    };

    tests["pad left"] = [&utility]() {
        // The quick red fox ... is a bad test, all words are over length of 3.
        if (auto const left_pad = utility.leftPad({"Sphinx", "of", "black", "quartz,", "judge", "my", "vow."}, '*');
                left_pad==str_vec{"Sphinx", "*of", "black", "quartz,", "judge", "*my", "vow."})
            return true;
        return false;
    };

    tests["combine"] = [&utility]() {
        str_vec test_vector{"Mr.Jones", "Mrs.Jones", "Mr.Smith", "Mrs.Smith", "Mr.Williams", "Mrs.Williams"};

        // Sorting to make sure they can simply be tested, as my implementation of combine sorts
        std::sort(test_vector.begin(), test_vector.end());
        auto combined = utility.combine({"Mr.", "Mrs."}, {"Jones", "Smith", "Williams"});
        return test_vector==combined;
    };

    for (auto[key, value]: tests) {
        std::cout << "Test: " << key << " " << (value() ? "passed" : "failed") << '\n';
    }
    return 0;
}