/**
 * Write a program that reads several city names from the keyboard
 * and displays only those names beginning with characters "B" or "C"
*/
#include <iostream>
#include <string>

#define MAX_BUF 20

void display(const std::string str[])
{
    for (int i = 0; i < MAX_BUF; i++)
    {
        if (!str[i].empty() && (str[i].at(0) == 'B' || str[i].at(0) == 'C'))
        {
            std::cout << str[i] << '\n';
        }
    }
}

int main()
{
    std::string cities[MAX_BUF];
    std::string temp_str{};

    std::cout << "\nENTER RANDOM CITES NAMES (# for exit):\n";

    int i = 0;
    while (i < MAX_BUF)
    {
        std::getline(std::cin, temp_str);

        if (temp_str.compare("#") == 0)
            break;

        cities[i] = temp_str;

        i++;
    }

    std::cout << "\nCITIES BEGINS WITH LETTER \'B\' OR \'C\':\n";
    display(cities);
    std::cout << '\n';

    return (0);
}