#include <iostream>
#include <iomanip>

const int LINEFEED = 0x0a;

void calc_whilespaces_letters_lines();
bool isnewline(unsigned int);

int main(int argc, char **argv)
{
    std::cout << "\nFIND NUMBER OF CHARACTERS, WHITESPACES & LINES:\n";
    std::cout << "INPUT TEXT (MARK THE END WITH '#'):\n\n";

    calc_whilespaces_letters_lines();

    std::cin.get();
    return EXIT_SUCCESS;
}

void calc_whilespaces_letters_lines()
{
    char ch;
    int num_of_whitespace, num_of_lines, num_of_characters;

    num_of_whitespace = num_of_lines = num_of_characters = 0;

    do
    {
        std::cin.get(ch);

        if (ch != '#')
        {
            if (isalnum(ch) || ispunct(ch))
                num_of_characters++;
            else if (isnewline(ch))
                num_of_lines++;
            else if (isspace(ch))
                num_of_whitespace++;
        }

    } while (ch != '#');

    std::cout << "\n";
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout << std::setw(28) << "Number of characters:";
    std::cout.setf(std::ios::right, std::ios::adjustfield);
    std::cout << std::setw(5) << num_of_characters << "\n";

    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout << std::setw(28) << "Number of whitespace:";
    std::cout.setf(std::ios::right, std::ios::adjustfield);
    std::cout << std::setw(5) << num_of_whitespace << "\n";

    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout << std::setw(28) << "Number of lines:";
    std::cout.setf(std::ios::right, std::ios::adjustfield);
    std::cout << std::setw(5) << num_of_lines << "\n";
}

bool isnewline(unsigned int ch)
{
    if (ch == LINEFEED)
        return true;
    return false;
}