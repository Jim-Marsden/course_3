//
// Created by james on 10/8/2021.
//

#include "SavingsAccount.h"

#include <iostream>
#include <locale> // May be included in sstream on some systems
#include <sstream>
#include <iomanip>

// for testing, to print out the money in a human friendly way depending on system locale
[[nodiscard]] std::string money_format_print(double pv){
    std::stringstream ss;
    ss.imbue(std::locale(""));

    // it truncates, so multiplying by 100 to get it the correct value. Should be correct for all locales.
    ss << std::showbase << std::put_money(std::to_string(pv * 100));
    return ss.str();
}


int main() {
    constexpr auto starting_money{1};

    JimMarsden::SavingsAccount my_account(starting_money);
    JimMarsden::SavingsAccount your_account(starting_money);


    JimMarsden::SavingsAccount::setAnnualInterestRate(0.027201);

    my_account.applyMonthlyInterest();
    your_account.applyMonthlyInterest();

    if(my_account.getSavingsBalance() != your_account.getSavingsBalance()) std::cerr << "That's not right :c\n";

    for (int i{0}; i < 12; ++i) {
        my_account.applyMonthlyInterest();
        std::cout << i << ' ' << money_format_print(my_account.getSavingsBalance()) << '\n';
    }
    if(my_account.getSavingsBalance() == your_account.getSavingsBalance()) std::cerr << "That's not right :c\n";


    for (int i{0}; i < 12; ++i) {
        your_account.applyMonthlyInterest();
        std::cout << money_format_print(your_account.getSavingsBalance()) << '\n';
    }

    return 0;
}