//
// Created by james on 10/8/2021.
//

#ifndef JIMMARSDEN_SAVINGSACCOUNT_H
#define JIMMARSDEN_SAVINGSACCOUNT_H

namespace JimMarsden {
    class SavingsAccount {
    public:
        // Constructors
        explicit SavingsAccount(double initialBalance);

        SavingsAccount() = delete;

        ~SavingsAccount() = default;

        SavingsAccount(SavingsAccount const &) = default;

        SavingsAccount(SavingsAccount &&) = default;

        SavingsAccount &operator=(SavingsAccount const &) = default;

        // Utilites

        [[nodiscard]] inline double getSavingsBalance() const noexcept;

        void applyMonthlyInterest() noexcept;

        //statics

        static void setAnnualInterestRate(double interest_rate)  noexcept;

    private:
        double savings_balance;
        static double interest_rate;
    };

    double SavingsAccount::getSavingsBalance() const noexcept {
        return savings_balance;
    }


} // namespace JimMarsden
#endif //JIMMARSDEN_SAVINGSACCOUNT_H
