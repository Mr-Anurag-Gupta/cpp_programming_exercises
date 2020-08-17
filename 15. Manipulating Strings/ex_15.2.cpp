/**
 * Write a program using an iterator and while() construct to display the
 * contents of a string object.
*/
#include <iostream>
#include <string>

int main()
{
    std::string str("Idiom: Cat got your tongue!");

    std::cout << "\nCONTENTS OF STRING:\n";

    std::string::iterator It = str.begin();
    while (It != str.end())
    {
        std::cout << *It;
        It++;
    }
    std::cout << "\n\n";

    return (0);
}