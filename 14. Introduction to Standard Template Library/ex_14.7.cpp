/**
 * A table gives a list of car model and the number of units sold in
 * each type in a specified period. Write a program to store this table
 * in a suitable container, and to display interactively the total value
 * of a particular model sold, given the unit cost of that model.
*/

#include <iostream>
#include <iomanip>
#include <map>

void display(std::map<std::string, std::tuple<float, int>> cars_list)
{
    std::cout << std::setw(10) << "Car Model"
              << std::setw(10) << "Price"
              << std::setw(10) << "Quantity"
              << std::setw(10) << "Price\n";

    float price = 0.0;
    int qty = 0;

    for (auto It = cars_list.begin(); It != cars_list.end(); It++)
    {
        price = std::get<0>(It->second);
        qty = std::get<1>(It->second);
        std::cout
            << std::setw(10) << It->first
            << std::setw(10) << std::setprecision(2)
            << std::setiosflags(std::ios_base::showpoint)
            << std::setiosflags(std::ios_base::fixed)
            << price
            << std::setw(10) << qty
            << std::setw(10) << price * qty << '\n';
    }
}

int main()
{
    // TABLE
    std::map<std::string, std::tuple<float, int>> cars_list{};

    // INSERT DATA
    cars_list.insert(cars_list.begin(), std::make_pair("CM001", std::make_tuple(850.99, 5)));
    cars_list.insert(cars_list.begin(), std::make_pair("CM002", std::make_tuple(1400.99, 1)));
    cars_list.insert(cars_list.begin(), std::make_pair("CM003", std::make_tuple(700.99, 3)));
    cars_list.insert(cars_list.begin(), std::make_pair("CM004", std::make_tuple(450.99, 2)));
    cars_list.insert(cars_list.begin(), std::make_pair("CM005", std::make_tuple(1340.90, 1)));

    display(cars_list);

    return (0);
}