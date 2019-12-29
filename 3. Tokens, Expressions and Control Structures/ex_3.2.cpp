/*
 * Problem:
 *  Write a function that creates a vector of user-given size M using
 *  new operator.
*/

#include <iostream>
#include <vector>
#include <cstdlib>

int main()
{
    const int M = 10;
    int *user = new int[M];
    delete[] user;
    return EXIT_SUCCESS;
}
