/*
 * Write a program containing a possible exception. Use a try block
 * to throw it and a catch block to handle it properly.
 */

#include <iostream>

int main()
{
    int x = 1, y = 0;
    float result;

    try
    {
        if (y == 0)
            throw y;
        result = x / y;
    }
    catch (int)
    {
        std::cout << "Exception occured: Divide by zero.\n";
    }

    return EXIT_SUCCESS;
}