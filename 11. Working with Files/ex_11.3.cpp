/**
 * Write a program that will create a data file containing the list of
 * telephone numbers given in Exercise 11.2. Use a class object to 
 * store each set of data.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

// structure.
class Contact
{
private:
    char name[10];
    char phone[10];

public:
    void readdata(void);
    void writedata(void);
};

void Contact::readdata(void) // read from keyboard
{
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter phone: ";
    std::cin >> phone;
}

void Contact::writedata(void)
{
    std::cout.setf(std::ios::right, std::ios::adjustfield);
    std::cout << std::setw(10) << name
              << std::setiosflags(std::ios::right)
              << std::setw(10) << phone << '\n';
}

int main()
{
    Contact contact[3];

    // Output file stream.
    std::ofstream fout("files/DIRECTORY.DAT", std::ios_base::out | std::ios_base::binary);

    // Check for failure.
    if (fout.fail())
    {
        std::cerr << "Error: Failed to open file.\n";
        exit(0);
    }

    std::cout << "ENTER DETAILS FOR THREE ITEMS:\n";
    for (int i = 0; i < 3; i++)
    {
        contact[i].readdata();
        fout.write((char *)&contact[i], sizeof(contact[i]));
    }

    fout.close();

    std::cout << "\nCONTENTS:\n";

    std::ifstream fin("files/DIRECTORY.DAT");
    for (int i = 0; i < 3; i++)
    {
        fin.read((char *)&contact[i], sizeof(contact));
        contact[i].writedata();
    }

    /*--------------EXIT MESSAGE--------------*/
    std::cout << "Press any to exit...";
    std::cin.get();
    return EXIT_SUCCESS;
}