/**
 * Write a program that reads a text file and creates another file that is identical
 * except that every sequence of consecutive blank space is replace by a single space.
*/

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    std::ifstream fin("read.txt");
    if (!fin)
    {
        std::cerr << "Error: Failed to open file 'read.txt'\n";
        exit(1);
    }

    std::ofstream fout("write.txt");
    if (!fout)
    {
        std::cerr << "Error: Failed to open file 'write.txt'\n";
        exit(1);
    }

    // Reading data
    char ch;
    unsigned short space_count = 0;
    while (fin.get(ch))
    {
        // Check if the character read is a space
        while (isblank(static_cast<unsigned char>(ch)))
        {
            space_count++;

            if (space_count % 2 == 0)
                space_count = 0;
            else if (space_count == 1)
                fout.put(ch);

            fin.get(ch);
        }

        if (space_count != 0)
            space_count = 0;

        fout.put(ch);
    }

    // Close files
    fin.close();
    fout.close();

    /*--------------EXIT MESSAGE--------------*/
    std::cout << "Press any to exit...";
    std::cin.get();
    return EXIT_SUCCESS;
}