/**
 * Write a program to demonstrate the concept of rethrowing an exception.
*/
#include <iostream>

void divide(int a, int b)
{
    try
    {
        if (b == 0)
            throw "Divide by zero";
        std::cout << "a/b = " << a / b << '\n';
    }
    catch (const char *error_msg)
    {
        std::cout << "Exception caught: " << error_msg << '\n';
        throw;
    }
}

int main()
{
    try
    {
        divide(10, 2);
        divide(1, 0); // rethrows an exception
    }
    catch (...)
    {
        std::cout << "Exception caught in main.\n";
    }
    return EXIT_SUCCESS;
}