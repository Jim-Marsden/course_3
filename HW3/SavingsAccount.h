//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/9/2021
// https://Jim-Marsden/course_3
// =====================================================================
// SavingsAccount.h Tested on the following compilers in C++17 standard
// MSVC - 14.19, clang 12.1, g++ 11.0
// Implementation of the SavingsAccount class
// Allows for a static way to update all interest globally for all
// SavingsAccounts.
//
// Prevents negative savings amounts
// =====================================================================
//

#ifndef JIMMARSDEN_SAVINGSACCOUNT_H
#define JIMMARSDEN_SAVINGSACCOUNT_H

namespace JimMarsden {
    class SavingsAccount {
    public:
        // Constructors


        // Sets SavingsAccount::savingsBallance. Valid range is 0..*.
        // If it is out of bounds, sets intialBallance to 0, and writes to STDERR
        explicit SavingsAccount(double initialBalance);

        SavingsAccount() = delete;

        ~SavingsAccount() = default;

        SavingsAccount(SavingsAccount const &) = default;

        SavingsAccount(SavingsAccount &&) = default;

        SavingsAccount &operator=(SavingsAccount const &) = default;

        // Utilites

        // Inlined because it is trivial, and doesn't have to expose includes.
        [[nodiscard]] inline double getSavingsBalance() const noexcept;

        // updates savingsBalance based on annualInterestRate / 12
        void applyMonthlyInterest() noexcept;

        //statics
        //Sets the annualInterestRate, validates it's 0..* and sets to 0, and prints to STDERR if not.
        static void setAnnualInterestRate(double interest_rate)  noexcept;

    private:
        double savingsBalance;
        static double annualInterestRate;
    };

    double SavingsAccount::getSavingsBalance() const noexcept {
        return savingsBalance;
    }


} // namespace JimMarsden
#endif //JIMMARSDEN_SAVINGSACCOUNT_H
