/**
 * Write a program that reads a list of countries in random order
 * and displays them in alphabetical order. Use comparison
 * operators and functions.
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdint>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> countries{};
    std::string city;

    std::cout << "\nEnter random city names (Type \'#\' for exit):\n";

    while (std::cin >> city)
    {
        if (city == "#")
            break;

        countries.push_back(city);
    }

    // sort the cities.
    std::sort(countries.begin(), countries.end(), std::less<std::string>());

    std::cout << "\nSorted list of countries:\n";
    std::vector<std::string>::const_iterator It = countries.begin();
    while (It != countries.end())
    {
        std::cout << *It << '\n';
        ++It;
    }
    std::cout << "\n";

    return (0);
}