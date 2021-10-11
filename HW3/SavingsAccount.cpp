//
// Created by james on 10/8/2021.
//

#include "SavingsAccount.h"

#include <iostream>


double JimMarsden::SavingsAccount::interest_rate{0.0};


void JimMarsden::SavingsAccount::setAnnualInterestRate(double interest_rate) noexcept {
    if (interest_rate < 0) {
        std::cerr << "The interest rate cannot go below 0.0f\n";
        SavingsAccount::interest_rate = 0;
    }
    JimMarsden::SavingsAccount::interest_rate = interest_rate;
}

JimMarsden::SavingsAccount::SavingsAccount(double initialBalance) : savings_balance{initialBalance} {}

void JimMarsden::SavingsAccount::applyMonthlyInterest() noexcept {
    const auto monthly_interest_rate{interest_rate / 12.f};
    savings_balance += savings_balance *  monthly_interest_rate;
}


