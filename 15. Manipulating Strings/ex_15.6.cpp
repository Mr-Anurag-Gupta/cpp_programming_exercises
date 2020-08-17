/**
 * Write a program that reads the following text and counts the number
 * of time the word 'It' appears in it.
 *      "It is new, It is singular."
 *      "It is simple. It must succeed!"
*/

#include <iostream>
#include <cstdint>
#include <string>

int main()
{
    std::string::size_type n = 0;
    short int it_count = 0;
    std::string line{};

    std::cout << "\nEnter following text:\n"
              << "\tIt is new, It is singular.\n"
              << "\tIt is simple, It must succeed!\n\n";

    for (int i = 0; i < 2; i++)
    {
        std::getline(std::cin, line);

        while ((n = line.find("It", n)) != std::string::npos)
        {
            n += 2;
            it_count += 1;
        }

        // reset n
        n = 0;
    }

    std::cout << "\nIt occured " << it_count << " times\n\n";

    return (0);
}