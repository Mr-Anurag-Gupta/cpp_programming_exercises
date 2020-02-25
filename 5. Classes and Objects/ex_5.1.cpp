/*
 * Define a class to represent a bank account. Include the
 * following members.
 * Data members
 *  1. Name of the depositor.
 *  2. Account number
 *  3. Type of account.
 *  4. Balance amount in the account.
 * Member functions
 *  1. To assign initial values
 *  2. To deposit an amount
 *  3. To withdraw an amount after checking the balance
 *  4. To display name and balance
 * Write a main program to test the program.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

enum Type
{
    SAVINGS,
    CURRENT
};

class Account
{
private:
    std::string name;
    Type type;
    std::string accountNumber;
    double balance;

public:
    Account();
    void initialize(std::string, Type, std::string, double);
    void deposit(double);
    void withdraw(double);
    void displayAccountInfo();
};

int main()
{
    Account acc;
    acc.initialize("Ravi Sharma", SAVINGS, "10021", 2000.0);
    acc.displayAccountInfo();

    acc.withdraw(2000);

    acc.displayAccountInfo();

    acc.deposit(100);

    acc.displayAccountInfo();
    acc.withdraw(101);

    std::cout
        << std::endl;
    return EXIT_SUCCESS;
}

Account::Account()
{
    balance = 0.0;
}

void Account::initialize(std::string name, Type typeOfAccount, std::string accountNumber, double initialAmount)
{
    this->name = name;
    this->type = typeOfAccount;
    this->accountNumber = accountNumber;
    this->balance = initialAmount;
}

void Account::deposit(double amount)
{
    balance += amount;
}

void Account::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
        std::cout << "\nRemaining balance: " << balance << std::endl;
    }
    else
        std::cout << "\nWithdrawl denied. Not enough money in the account." << std::endl;
}

void Account::displayAccountInfo()
{
    std::cout << "\nAccount Information" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << std::setw(9) << "Name:"
              << std::setw(13) << name << std::endl;
    std::cout << std::setw(9) << "Balance:"
              << std::setw(13) << balance << std::endl;
}