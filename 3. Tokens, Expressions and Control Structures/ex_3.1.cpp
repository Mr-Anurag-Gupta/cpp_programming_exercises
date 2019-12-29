/*
    Problem:
        Write a program using reference variables as arguments to swap the
        values of a pair of integers.
*/

#include <iostream>
#include <cstdlib>

void swap(int &, int &);

int main()
{
    int a, b;
    a = 5;
    b = 10;

    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    return EXIT_SUCCESS;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = a;
}