/**
 * Write a program with the following:
 * (a) A function to read two double type numbers from keyboard.
 * (b) A function to calculate the division of these two numbers.
 * (c) A try block to throw an exception when a wrong type of data
 *     is keyed in.
 * (d) A try block to detect and throw an exception if the condition
 *     "divide-by-zero" occurs.
 * (e) Appropriate catch block to handle the exceptions thrown.
*/

#include <iostream>

void read(double &, double &);
void divide(const double &, const double &);

int main()
{
    double a, b;

    try
    {
        read(a, b);
        divide(a, b);
        std::cout << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << "\nException caught in main.\n\n";
    }

    return EXIT_SUCCESS;
}

void read(double &a, double &b)
{
    try
    {
        std::cout << "\nEnter value for a: ";
        std::cin >> a;
        std::cout << "\nEnter value for b: ";
        std::cin >> b;

        // throw an exception in case of wrong data.
        if (std::cin.fail())
            throw std::runtime_error("Wrong type of data provided.");
    }
    catch (const std::exception &e)
    {
        std::cout << "\n\nException caught: " << e.what();
        throw;
    }
}

void divide(const double &a, const double &b)
{
    try
    {
        if (b == 0.0)
            throw std::runtime_error("Divide by zero.");
        std::cout.precision(2);
        std::cout.setf(std::ios_base::showpoint);
        std::cout << "\nresult (a / b) = " << a / b;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "\nException caught: " << e.what();
        throw;
    }
}