/*
 * Problem 4.6:
 *  Redo exercise 4.5 using inline function. Test the function
 *  using the main program.
*/

#include <iostream>
#include <cmath>

inline int getMax(int, int);
inline int getMaxOfThree(int, int, int);

int main()
{
    int a, b, c;

    // Testcase 1:
    a = 3;
    b = 4;
    c = 2;
    std::cout << "a=3, b=4, c=2 | largest=" << getMaxOfThree(a, b, c) << std::endl;

    // Testcase 2:
    a = 3;
    b = 1;
    c = 2;
    std::cout << "a=3, b=4, c=2 | largest=" << getMaxOfThree(a, b, c) << std::endl;

    return EXIT_SUCCESS;
}

inline int getMax(int a, int b)
{
    return ((a > b) ? a : b);
}

inline int getMaxOfThree(int a, int b, int c)
{
    return ((getMax(a, b)) > c ? getMax(a, b) : c);
}