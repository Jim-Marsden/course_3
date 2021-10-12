//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/9/2021
// https://Jim-Marsden/course_3
// =====================================================================
// SavingsAccount.cpp Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 11.0
// Implementation of the SavingsAccount class
// Allows for a static way to update all interest globally for all
// SavingsAccounts.
//
// Prevents negative savings amounts
// =====================================================================
//
#include "SavingsAccount.h"

#include <iostream>

double JimMarsden::SavingsAccount::annualInterestRate{0.0};


/*
 * Validates that val is 0..*.
 * If val is not valid, set it to 0 and prints message to STDERR.
 *
 * This is a template to avoid assuming types.
 */
template<class validation_t, class message_t>
constexpr static validation_t validate_above_0(validation_t const & val, message_t const &message) {
    if (val < 0) {
        std::cerr << message << '\n';
        return 0;
    }
    return val;
}

//Constructors ==========================================================

JimMarsden::SavingsAccount::SavingsAccount(double initialBalance) :
        savingsBalance{validate_above_0(initialBalance, "The initial balance cannot be below 0")} {}


// updates savingsBalance based on annualInterestRate / 12
void JimMarsden::SavingsAccount::applyMonthlyInterest() noexcept {
    const auto monthly_interest_rate{annualInterestRate / 12.f};
    savingsBalance += savingsBalance * monthly_interest_rate;
}


// Statics

void JimMarsden::SavingsAccount::setAnnualInterestRate(double interest_rate) noexcept {
    SavingsAccount::annualInterestRate = validate_above_0(interest_rate, "The interest rate cannot go below 0.0f");
}


