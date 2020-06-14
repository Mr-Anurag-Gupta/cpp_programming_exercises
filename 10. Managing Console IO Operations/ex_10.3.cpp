#include <iostream>
#include <iomanip>

void calc_whitespaces_letters_lines();

int main(int argc, char **argv)
{
    std::cout << "\nFIND NUMBER OF CHARACTERS, WHITESPACES & LINES";
    std::cout << "\nINPUT TEXT (MARK THE END WITH '#'):\n";

    calc_whitespaces_letters_lines();

    std::cin.get();
    return EXIT_SUCCESS;
}

void calc_whitespaces_letters_lines()
{
    char ch;
    int num_of_lines, num_of_whitespaces, num_of_characters;

    num_of_lines = num_of_whitespaces = num_of_characters = 0;

    do
    {
        // scan the character from the stdin.
        std::cin.get(ch);

        // logic
        if (ch != '#')
        {
            if (isalnum(ch) || ispunct(ch))
                num_of_characters++;
            else if (ch == '\n')
                num_of_lines++;
            else if (isspace(ch))
                num_of_whitespaces++;
        }

    } while (ch != '#');

    std::cout << "\n";
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout << std::setw(28) << "Number of characters:";
    std::cout.setf(std::ios::right, std::ios::adjustfield);
    std::cout << std::setw(5) << num_of_characters;

    std::cout << "\n";
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout << std::setw(28) << "Number of whitespaces:";
    std::cout.setf(std::ios::right, std::ios::adjustfield);
    std::cout << std::setw(5) << num_of_whitespaces;

    std::cout << "\n";
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout << std::setw(28) << "Number of lines:";
    std::cout.setf(std::ios::right, std::ios::adjustfield);
    std::cout << std::setw(5) << num_of_lines << "\n";
}
