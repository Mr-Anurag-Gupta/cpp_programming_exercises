/*
 * Problem:
 *  Write a program to evaluate following expressions with accuracy 0.0001
 *      sin x = x - (x^3/3!) + (x^5/5!) - ..., gen. [((-1)^k/(2k+1)!) * x^(2k+1)]
 *      cos x = 1 - (x^2/2!) + (x^4/4!) - ..., gen. [((-1)^k/(2k)!) * x^(2k)]
 *      SUM   = 1 + (1/2)^2 + (1/3)^3 + ..., gen. [(1/k)^k]
 *      where k ranges from 0 - infinity
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

double calcSin(float deg, float accuracy);
double calcCos(float deg, float accuracy);
double calcSum(int n, float accuracy);
int factorial(int);

int main()
{
    const int n = 3;
    const float deg = 30;
    const float accuracy = 0.0001;

    std::cout << "sin(30) = " << calcSin(deg, accuracy) << std::endl;
    std::cout << "cos(60) = " << calcCos(60, accuracy) << std::endl;
    std::cout << "sum(3) = " << calcSum(n, accuracy) << std::endl;

    return EXIT_SUCCESS;
}

double calcSin(float deg, float accuracy)
{
    /* convert degree to radian */
    deg = deg * (3.142 / 180.0);

    float sinval = sin(deg);
    float sinx = 0.0;

    int toThePower = 0;
    int fact = 0;

    int i = 0;
    do
    {
        toThePower = 2 * i + 1;
        fact = factorial(toThePower);
        sinx += ((pow(-1, i) / fact) * pow(deg, toThePower));
        i++;
    } while (accuracy <= fabs(sinval - sinx));

    return sinval;
}

double calcCos(float deg, float accuracy)
{
    /* convert degree to radian */
    deg = deg * (3.142 / 180.0);

    float cosval = cos(deg);
    float cosx = 0.0;

    int toThePower = 0;
    int fact = 0;

    int i = 0;
    do
    {
        toThePower = 2 * i;
        fact = factorial(toThePower);
        cosx += ((pow(-1, i) / fact) * pow(deg, toThePower));
        i++;
    } while (accuracy <= fabs(cosval - cosx));

    return cosval;
}

double calcSum(int n, float accuracy)
{
    double sum = 0.0;

    for (int i = 1; i <= n; i++)
    {
        sum += 1 / pow(i, i);
        std::cout << sum << std::endl;
    }

    return sum;
}

int factorial(int x)
{
    if (x == 1 || x == 0)
        return 1;
    else
        return x * factorial(x - 1);
}