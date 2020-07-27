/**
 * A file contains a list of telephone numbers in the following form:
 * John     23456
 * James    9876
 * ...      ...
 * The names contain only one word and the names and telephone numbers are
 * separated by white spaces. Write a program to read the file and output
 * the list in two columns. The names should be left-justified and the 
 * numbers right-justified.
 */

#include <iostream>
#include <fstream>
#include <iomanip>

#define FILES_PATH "files/"

void readfile(std::string filename);
bool checkEOF(std::ifstream &);

int main(int argc, char *argv[])
{
    std::string filename = "TelephoneDirectory.dat";

    readfile(filename);

    /*--------------EXIT MESSAGE--------------*/
    std::cout << "Press any to exit...";
    std::cin.get();
    return EXIT_SUCCESS;
}

void readfile(std::string filename)
{
    // Create input stream.
    std::ifstream fin(FILES_PATH + filename, std::ios_base::in);

    // try
    // {
    //     // Setting exception mask.
    //     // NOTE: This tells compiler to throw exception when
    //     //       following iostate's are set.
    //     fin.exceptions(fin.failbit | fin.badbit);

    //     // Open file.
    //     fin.open(FILES_PATH + filename, std::ios_base::in);
    // }
    // catch (std::ios_base::failure &e)
    // {
    //     std::cerr << "Caught an ios_base::failure.\n"
    //               << "Explanatory string: " << e.what() << '\n'
    //               << "Error code: " << e.code() << '\n';
    // }

    // Reading data.
    std::string data;
    while (!fin.eof())
    {
        fin >> data;

        // Check if data read is successful.
        if (checkEOF(fin))
            break;

        std::cout.setf(std::ios::left, std::ios::adjustfield);
        std::cout << std::setw(10) << data;

        fin >> data;

        // Check if data read is successful.
        if (checkEOF(fin))
            break;

        std::cout.setf(std::ios::right, std::ios::adjustfield);
        std::cout << std::setw(10) << data;

        std::cout << "\n";
    }

    fin.close();
}

bool checkEOF(std::ifstream &fin)
{
    if (fin.eof())
    {
        return true;
    }
    return false;
}