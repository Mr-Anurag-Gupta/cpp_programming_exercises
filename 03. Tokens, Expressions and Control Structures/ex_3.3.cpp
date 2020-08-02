/*
 * Problem:
 *  Write a program to print the following output using for loops.
 *  1
 *  22
 *  333
 *  4444
 *  55555
 *  ......
*/

#include <iostream>
#include <cstdlib>

int main()
{
    int n;

    std::cout << "Enter a number print the pattern: ";
    std::cin >> n;

    /* printf the pattern for 1 to n numbers. */
    for (auto i = 1; i <= n; i++)
    {
        for (auto j = 1; j <= i; j++)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}