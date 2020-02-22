/*
 * Problem 4.9:
 *  Write a program to compute the area of a triangle and a
 *  circle by overloading the area() function.
*/

#include <iostream>
#include <cassert>
#include <cmath>

inline double area(double b, double h);
inline double area(double r);

int main()
{
    double b, h, r;
    b = 2;
    h = 5;
    r = 3;

    std::cout << "Area of circle: " << area(r) << "\n"
              << std::endl;

    std::cout << "Area of triangle " << area(b, h) << "\n"
              << std::endl;

    return EXIT_SUCCESS;
}

inline double area(double b, double h)
{
    return (0.5 * b * h);
}

inline double area(double r)
{
    return (M_PI * pow(r, 2));
}