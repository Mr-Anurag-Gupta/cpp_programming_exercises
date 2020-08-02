/*
 * Problem:
 *  An electric board charges the following rates to
 *  domestic users.
 *   For the first 100 units - 60P per unit
 *   For next 200 units      - 80P per unit
 *   Beyond 300              - 90P per unit
 *  All users are charged minimum Rs. 50.00. If the 
 *  total amount is more than Rs. 300.00 then an
 *  additional surcharge of 15% is added.
 *  Write a program to read the names of users and
 *  number of units consumed and print out the charges
 *  with names.
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <map>
#include <cmath>

void readRecord(std::map<std::string, int> &);
void generateBill(std::map<std::string, int>);
int calcCharges(int);

int main()
{
    std::map<std::string, int> recordsDB;
    readRecord(recordsDB);
    generateBill(recordsDB);
    return EXIT_SUCCESS;
}

void readRecord(std::map<std::string, int> &recordsDB)
{
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Electricity Consumption Record / Database" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    int numOfRecords;
    std::cout << "Please input number of records to be inserted: " << std::endl;
    std::cin >> numOfRecords;

    std::cout << "\nEnter the details in (userName, unitsConsumed) format:" << std::endl;
    int i = 0;
    do
    {
        char buf[30] = {'\0'};
        int unitsConsumed = 0;
        std::cout << "Record " << (i + 1) << ": ";
        std::cin >> buf >> unitsConsumed;
        recordsDB.insert(std::pair(buf, unitsConsumed));
        i++;
    } while (i < numOfRecords);
}

int calcCharges(int unitsConsumed)
{
    float charges = 0.0;
    if (unitsConsumed <= 100)
        charges = unitsConsumed * 0.60;
    else if (unitsConsumed <= 300)
        charges = unitsConsumed * 0.80;
    else
        charges = unitsConsumed * 0.90;

    if (charges < 50.0)
        charges = 50.0;
    else if (charges > 300.0)
        charges = charges + (charges * 0.15);

    return charges;
}

void generateBill(std::map<std::string, int> recordsDB)
{
    std::cout << std::endl
              << "Charges as per usage:\n"
              << std::endl;
    std::cout << std::setw(20) << "username"
              << std::setw(20) << "units consumed"
              << std::setw(15) << "charges" << std::endl;
    for (auto it = recordsDB.begin(); it != recordsDB.end(); it++)
    {
        float charges = calcCharges(it->second);
        std::cout << std::setw(20) << it->first
                  << std::setw(20) << it->second
                  << std::setw(15) << std::setprecision(8) << charges << std::endl;
    }

    std::cout << std::endl;
}
