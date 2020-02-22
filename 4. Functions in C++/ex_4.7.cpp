/*
 * Problem 4.7:
 *  Write a function power() to raise a number m to a power n. The function takes 
 *  a double value for m and int value for n, and returns the result correctly. 
 *  Use a default value of 2 for n to make the function to calculate squares when 
 *  this argument is omitted. Write a main that gets the values of m and n from 
 *  the user to test the function
*/

#include <iostream>
#include <cassert>
#include <cmath>

double power(double, int);

int main()
{
    double m;
    int n;

    std::cout << "\nDemonstration of power() function:" << std::endl;
    std::cout << "Input values for (m, n), should be space seperated. ";
    std::cin >> m;
    std::cin >> n;

    std::cout << "Result: " << power(m, n) << "\n"
              << std::endl;

    return EXIT_SUCCESS;
}

double power(double m, int n = 2)
{
    double result = m;
    for (auto i = 1; i < n; i++)
        result *= m;
    return result;
}