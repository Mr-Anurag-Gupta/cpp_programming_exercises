/*
 * Problem:
 *  Write a program to evaluate the following investment equation
 *      V = P(1+r)^n
 *      where P is the principal amount,
 *            V is the Value of money at the end on n years,
 *            & r is the rate.
 * 
 * Dataset:
 *  P: 1000, 2000, ... , 10000
 *  r: 0.11, 0.12, ..., 0.20
 *  n: 1, 2, 3, ... , 10
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

void calcMoneyAfterNYears(int[], float[], int);

int main()
{
    const int n = 10;
    int principal[n] = {0};
    float rate[n] = {0};

    /* Initialize the dataset with sample data. */
    for (auto i = 1; i <= n; i++)
    {
        principal[i - 1] = 1000 * i;
        rate[i - 1] += (i * 0.01) + 0.10;
    }

    calcMoneyAfterNYears(principal, rate, n);

    return EXIT_SUCCESS;
}

/*
 * Function:  calcMoneyAfterNYears
 * -------------------------------
 * Calculates the investment equation,
 *      V = P(1+r)^n
 *
 *  principal: an array of principal amounts.
 *       rate: an array of rates.
 *          n: number of years.
 *
 *  returns: value of money after n years.
 */
void calcMoneyAfterNYears(int principal[], float rate[], int n)
{
    double total_amount = 0;
    
    std::cout << std::setw(15) << "Principals"
              << std::setw(8) << "Rates"
              << std::setw(8) << "Years"
              << std::setw(15) << "Value" << std::endl;;
    
    for (auto i = 0; i < n; i++)
    {
        total_amount += principal[i] * pow(1 + rate[i], i+1);
        std::cout << std::setw(15) << principal[i]
                  << std::setw(8) << rate[i]
                  << std::setw(8) << i
                  << std::setw(15) << std::setprecision(2) << total_amount << std::endl;
    }
}
