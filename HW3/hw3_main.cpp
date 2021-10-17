//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/9/2021
// https://Jim-Marsden/course_3
// =====================================================================
// hw3.cpp Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 11.0
// Tests the HW3/SavingsAccount class.
// =====================================================================
//
#include "SavingsAccount.h"

#include <iostream>
#include <sstream>
#include <iomanip>

// for testing, to print out the money in a human friendly way depending on system locale
[[nodiscard]] std::string money_format_print(double pv) {
    std::stringstream ss;
    ss.imbue(std::locale(""));

    // it truncates, so multiplying by 100 to get it the correct value. Should be correct for all locales.
    ss << std::showbase << std::put_money(std::to_string(pv * 100));
    return ss.str();
}


/*
 * Symmetrical things will be done to two different objects, and they should end at the same value, and will be checked
 * accordingly.
 *
 * Will also validate if the constructor and setAnnualInterestRate() validates properly.
 */
int main() {
    constexpr auto starting_money{1000.0}; // for consistant construction
    constexpr auto interest_rate{0.027201}; // The rate from 2020

    JimMarsden::SavingsAccount my_account(starting_money);
    JimMarsden::SavingsAccount your_account(starting_money);
    JimMarsden::SavingsAccount invalid_amount(-starting_money); // Should print to STDERR.


    JimMarsden::SavingsAccount::setAnnualInterestRate(-interest_rate); // Should print to STDERR.
    JimMarsden::SavingsAccount::setAnnualInterestRate(interest_rate);
    my_account.applyMonthlyInterest();
    your_account.applyMonthlyInterest();

    if (my_account.getSavingsBalance() != your_account.getSavingsBalance())
        std::cerr << "my_account and your account should be the same.\n";
    else std::cout << "test passed.\n";

    for (int i{0}; i < 12; ++i) { // Interest over 12 months
        my_account.applyMonthlyInterest();
    }
    if (my_account.getSavingsBalance() == your_account.getSavingsBalance())
        std::cerr << "my_account and your_account should be the same.\n";
    else std::cout << "test passed.\n";

    for (int i{0}; i < 12; ++i) { // Interest over 12 months
        your_account.applyMonthlyInterest();
    }

    if (my_account.getSavingsBalance() != your_account.getSavingsBalance())
        std::cerr << "my_account and your account should be the same.\n";
    else std::cout << "test passed.\n";

    std::cout << std::endl << "Starting value: " << money_format_print(starting_money) << "\n";
    std::cout << "your account final balance: " << money_format_print(your_account.getSavingsBalance()) << "\n";
    std::cout << "my account final balance: " << money_format_print(my_account.getSavingsBalance()) << '\n';

    return 0;
}