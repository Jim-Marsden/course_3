//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 11/05/2021
// =====================================================================
// StringUtility.cpp Tested on Linux on Clang 12 and g++ 11.1.0 built with C++17
// https://Github.com/Jim-Marsden/course_3
//
// A class with 4 member functions: Join, Reverse Combine, and LeftPad
// =====================================================================

#include "StringUtility.h"
#include <algorithm>
#include <iterator> // for std::back_inserter

auto JimMarsden::StringUtility::join(const std::vector<std::string>& strings,
        char delimiter) const -> std::string
{
    if(strings.empty()) return {}; // so substr doesn't remove for a string of length 0.
    std::string buffer;
    for(auto const & element : strings){
        buffer += element;
        buffer += delimiter;
    }
    return buffer.substr(0, buffer.size()  - 1); // To remove trailing delimiter.
}

auto JimMarsden::StringUtility::reverse(const std::vector<std::string>& strings) const -> std::vector<std::string>
{
    auto buffer = strings;
    std::reverse(buffer.begin(),  buffer.end());
    return buffer;
}

auto JimMarsden::StringUtility::combine(const std::vector<std::string>& left, const std::vector<std::string>& right) const -> std::vector<std::string>
{
    // This is a great use case for C++20's ranges.
    std::vector<std::string> result;

    for(auto const & left_element: left){
        for(auto const & right_element : right){
            result.push_back(left_element + right_element);
        }
    }
    std::sort(result.begin(),  result.end()); // The spec said order doesn't matter, so might as well sort!
    return result;
}

auto JimMarsden::StringUtility::leftPad(const std::vector<std::string>& strings, char pad) const -> std::vector<std::string>
{
    auto buffer{strings};
    for(auto & element : buffer){
        if(auto size = element.size(); size < 3) element.insert(0, +(3 - size), pad);
    }
    return buffer;
}
