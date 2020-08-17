/**
 * Write a program that counts number of occurrences of a particular character,
 * say 'e', in a line of text.
*/

#include <iostream>  // cout, cin
#include <algorithm> // count, transform
#include <string>
#include <vector>

int main()
{
    // store line read from stdout.
    std::string line{};

    // store lines.
    std::vector<std::string> lines;

    std::cout << "\nEnter 3 lines of text:\n";

    // reads lines.
    for (int i = 0; i < 3; i++)
    {
        std::getline(std::cin, line);
        lines.push_back(line);
    }

    char ch;
    std::cout << "\nInput a charater to be searched: ";
    std::cin >> ch;

    line = {};
    for (int i = 0; i < lines.size(); i++)
    {
        line = lines.at(i);

        // convert given string into lowercase.
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);

        ch = tolower(ch);

        std::cout << "\nNumber of \'" << ch << "\' on line " << (i + 1)
                  << ": "
                  << std::count(line.begin(), line.end(), (char)ch);
    }

    std::cout << "\n\n";

    return (0);
}