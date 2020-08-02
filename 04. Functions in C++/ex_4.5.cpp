/*
 * Problem 4.5:
 *  Write a macro that obtains the largest of three
 *  numbers.
*/

#include <iostream>
#include <cmath>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define GET_LARGEST(a, b, c) \
    (((MAX(a, b)) > (c)) ? MAX(a, b) : (c))

int main()
{
    int a, b, c;

    // Testcase 1:
    a = 3;
    b = 4;
    c = 2;
    std::cout << "a=3, b=4, c=2 | largest=" << GET_LARGEST(a, b, c) << std::endl;

    // Testcase 2:
    a = 3;
    b = 1;
    c = 2;
    std::cout << "a=3, b=4, c=2 | largest=" << GET_LARGEST(a, b, c) << std::endl;

    return EXIT_SUCCESS;
}