/*
 * Problem:
 *  Write a program to find the variance and standard deviation
 *  of N numbers.
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>

double calcVariance(std::vector<int>);
double calcStandartDeviation(std::vector<int>);
double calcMean(std::vector<int>);

template <typename T>
T sum(std::vector<T>);

int main()
{
    std::vector<int> arr = {60, 56, 61, 68, 51, 53, 69, 54};

    std::cout << "mean = " << calcMean(arr) << std::endl;
    std::cout << "variance = " << calcVariance(arr) << std::endl;
    std::cout << "standard variance = " << calcStandartDeviation(arr) << std::endl;

    return EXIT_SUCCESS;
}

template <typename T>
T sum(std::vector<T> arr)
{
    T sum = T(0);
    for (auto it = arr.begin(); it <= arr.end(); it++)
        sum += *it;
    return sum;
}

double calcMean(std::vector<int> arr)
{
    return sum(arr) / double(arr.size());
}

double calcVariance(std::vector<int> arr)
{
    double sum = 0.0;
    double xBar = calcMean(arr);
    for (auto it = arr.begin(); it != arr.end(); it++)
        sum += pow(*it - xBar, 2);
    return sum / double(arr.size());
}

double calcStandartDeviation(std::vector<int> arr)
{
    return sqrt(calcVariance(arr));
}
