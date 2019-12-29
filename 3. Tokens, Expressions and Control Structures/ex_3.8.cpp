/*
 *   Problem:
 *      Compute the value of the function y=e^-x
 *      for x varying from 0 to 10 in the steps 0.1
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

int main()
{
    std::cout << std::setw(5) << "X"
              << std::setw(10) << "Y" << std::endl;
    for (auto i = 0.1f; i < 1.0f; i += 0.1f)
    {
        std::cout << std::setw(5) << i
                  << std::setw(10) << std::exp(-i) << std::endl;
    }
    return EXIT_SUCCESS;
}