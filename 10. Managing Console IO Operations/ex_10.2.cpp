#include <iostream>
#include <iomanip>

using namespace std;

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
    cout.fill('-');
    cout.precision(2);
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed, ios::floatfield);

    cout << "\n";
    cout.setf(ios::left, std::ios::adjustfield);
    cout << setw(15) << "NAME" << setw(8) << "CODE";

    cout.setf(ios::right, ios::adjustfield);
    cout << setw(8) << "COST";

    cout << "\n";

    for (int i = 0; i < num_of_records; i++)
    {
        cout.setf(ios::left, ios::adjustfield);
        cout << setw(15) << records[i].name;
        cout << setw(8) << records[i].code;

        cout.setf(ios::right, ios::adjustfield);
        cout << setw(8) << records[i].cost;
        cout << "\n";
    }

    cout.unsetf(ios::left);
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