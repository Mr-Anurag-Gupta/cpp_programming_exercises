/*
 * Problem 4.7:
 *  Write a function that performs the same operation as that
 *  of exercise 4.7 but takes an int value for m. Both the function
 *  should have the same name. Write a main that calls the functions.
 *  Use the concept of function overloading.
*/

#include <iostream>
#include <cassert>
#include <cmath>

double power(double, int);
double power(int, int);

int main()
{
    double m = 4.0;
    int m1 = 3, n;

    std::cout << "\nDemonstration of power() function:" << std::endl;

    std::cout << "Result: " << power(m, n) << "\n"
              << std::endl;

    std::cout << "Result: " << power(m1, n) << "\n"
              << std::endl;

    return EXIT_SUCCESS;
}

double power(int m, int n)
{
    std::cout << "\nExecuting (int)...\n"
              << std::endl;
    double result = m;
    for (auto i = 1; i < n; i++)
        result *= m;
    return result;
}

double power(double m, int n = 2)
{
    std::cout << "\nExecuting (double)...\n"
              << std::endl;
    double result = m;
    for (auto i = 1; i < n; i++)
        result *= m;
    return result;
}