/**
 * Write a program that will read a line of text containing more than
 * three words and replace all the blank spaces with an underscore(_).
*/

#include <iostream>
#include <cctype>
#include <string>

int main()
{
    std::string str{};
    short int no_of_words = 1;

    std::cout << "\nEnter a line with more than 3 works:\n";
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (isblank(ch))
            no_of_words++;

        str += ch;
    }

    if (no_of_words < 4)
    {
        std::cerr << "\nline doesn't contain enough works\n\n";
        exit(0);
    }

    std::string::iterator It = str.begin();
    for (; It != str.end(); It++)
    {
        if (*It == ' ')
            *It = '_';
    }

    std::cout << "\nString after replacing with underscore(_):\n";
    std::cout << str << "\n\n";

    return (0);
}