#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

const int SIZE = 2;
const int BUFFER_SIZE = 15;

struct RECORD
{
    char name[BUFFER_SIZE];
    int code;
    float cost;
};

void display_table(RECORD *records, int num_of_records)
{
    cout.precision(2);
    cout.setf(std::ios::showpoint);
    cout.setf(std::ios::fixed, std::ios::floatfield);

    cout.setf(std::ios::left, std::ios::adjustfield);
    cout << std::setw(15) << "NAME" << std::setw(8) << "CODE";

    cout.setf(std::ios::right, std::ios::adjustfield);
    cout << std::setw(8) << "COST";

    cout << "\n";

    for (int i = 0; i < num_of_records; i++)
    {
        cout.setf(std::ios::left, std::ios::adjustfield);
        cout << std::setw(15) << records[i].name;
        cout << std::setw(8) << records[i].code;

        cout.setf(std::ios::right, std::ios::adjustfield);
        cout << std::setw(8) << records[i].cost;
        cout << "\n";
    }

    cout.unsetf(std::ios::left);
    cout.precision(0);
}

int main(int argc, char **argv)
{
    RECORD records[SIZE];
    cout << "\nInput ITEM, CODE, COST (line separated) for :\n";

    int i = 0;
    while (i < SIZE)
    {

        cin.getline(records[i].name, BUFFER_SIZE);
        fflush(stdin);
        cin >> records[i].code;
        fflush(stdin);
        cin >> records[i].cost;
        fflush(stdin);
        i++;
    }

    display_table(records, SIZE);

    return EXIT_SUCCESS;
}