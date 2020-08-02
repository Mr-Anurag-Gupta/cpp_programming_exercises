/*
 * Modify the class and the program of Exercise 5.1 for handling 10 customers.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
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
    Account() { balance = 0.0; };
    void initialize(std::string, Type, std::string, double);
    void deposit(double amount) { balance += amount; };
    void withdraw(double);
    void displayAccountInfo();
};

class Bank
{
public:
    Account customers[10];
};

int main()
{
    std::string names[10] = {
        "Harry Potter",
        "Ronald Wiseley",
        "Harminy Granjel",
        "Hugh Jackman",
        "Ryan Renolds",
        "James Bond",
        "Daniel Radcliff",
        "Chris Hemsworth",
        "Chris Evans",
        "Robert Downy Jr."};

    Bank bank;

    for (auto i = 0; i < 10; i++)
    {
        bank.customers[i].initialize(names[i], SAVINGS, std::to_string(i + 100), 1000.0 * i);
        bank.customers[i].displayAccountInfo();
    }

    return EXIT_SUCCESS;
}

void Account::initialize(std::string name, Type typeOfAccount, std::string accountNumber, double initialAmount)
{
    this->name = name;
    this->type = typeOfAccount;
    this->accountNumber = accountNumber;
    this->balance = initialAmount;
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
    // std::cout << "\nAccount Information" << std::endl;
    // std::cout << "---------------------------------" << std::endl;
    std::cout << std::setw(12) << "Name:"
              << std::setw(18) << name << std::endl;
    std::cout << std::setw(12) << "Balance:"
              << std::setw(18) << balance << std::endl;
}