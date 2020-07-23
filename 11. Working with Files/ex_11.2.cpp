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
#include <map>

#define FILES_PATH "files/"

void readfile(std::string filename);
//void output_directory(std::map<std::string, std::string> teldirectory);

int main(int argc, char *argv[])
{
    std::string filename = "ex_11_2_teldirectory.dat";

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
    try
    {
        fin.exceptions(fin.failbit);
    }
    catch (std::ios_base::failure &e)
    {
        std::cerr << "Caught an ios_base::failure.\n"
                  << "Explanatory string: " << e.what() << '\n'
                  << "Error code: " << e.code() << '\n';
    }

    // Reading data.
    constexpr int SIZE = 100;
    char line[SIZE] = {'\0'};
    while (fin.getline(line, SIZE))
    {
        std::cout << line << std::endl;
    }

    fin.close();
}