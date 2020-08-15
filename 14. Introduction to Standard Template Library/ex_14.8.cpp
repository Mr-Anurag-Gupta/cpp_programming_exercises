/**
 * Write a program that accepts a shopping list of five items from the keyboard
 * and store them in a vector. Extend the program to accomplish the 
 * following:
 * (a) To delete a specified item in the list
 * (b) To add an item at a specified location
 * (c) To add an item in the end
 * (d) To print the contents of the vector
*/

#include <iostream>
#include <vector>
#include <string>

const int SIZE = 5;
const int MAX_BUF = 20;

void readdata(std::vector<std::string> &shopping_list)
{
    std::cout << "\nENTER 5 ITEMS FOR SHOPPING\n";
    char item[MAX_BUF];
    for (int i = 0; i < SIZE; i++)
    {
        std::cin.getline(item, MAX_BUF);
        shopping_list.push_back(item);
    }
}

void display(const std::vector<std::string> &shopping_list)
{
    std::cout << "\nShopping list\n";
    for (auto item : shopping_list)
    {
        std::cout << item << '\n';
    }
}

void delete_item(std::vector<std::string> &shopping_list)
{
    bool is_deleted = false;
    std::string item;

    std::cout << "\nEnter item to delete: ";
    std::getline(std::cin, item);

    std::vector<std::string>::const_iterator It = shopping_list.begin();
    for (; It != shopping_list.end(); It++)
    {
        if (*It == item)
        {
            shopping_list.erase(It);
            std::cout << "\n\'"
                      << item << "\' deleted from the shopping list\n";
            is_deleted = true;
            break;
        }
    }

    if (!is_deleted)
    {
        std::cout << "\n\'"
                  << item << "\' is not found\n";
    }
}

void add_item(std::vector<std::string> &shopping_list)
{
    std::string item;
    short int index;

    std::cout << "\nEnter item to add: ";
    std::getline(std::cin, item);

    std::cout << "\nSpecify location for the item \'" << item << "\': ";
    std::cin >> index;

    if (index <= shopping_list.size())
    {
        shopping_list[index - 1] = item;
        std::cout << "\nItem \'" << item << "\' added successfully at index " << index << '\n';
    }
    else
    {
        std::cerr << "\nError: location specified is beyond the size of shopping list" << '\n';
    }
}

void append_item(std::vector<std::string> &shopping_list)
{
    std::string item;

    std::cout << "\nEnter item: ";
    std::getline(std::cin, item);

    shopping_list.push_back(item);

    std::cout << "\nItem \'" << item << "\' appended successfully\n";
}

int main()
{
    std::vector<std::string> shopping_list{};

    readdata(shopping_list);

    short int option;

    do
    {
        std::cout << "\nChoose the options:\n"
                  << "(1) Delete an item\n"
                  << "(2) Add an item\n"
                  << "(3) Append item\n"
                  << "(4) Display shopping list\n"
                  << "(5) Exit\n";
        std::cout << "\nOption: ";
        std::cin >> option;

        // To avoid reading '\n' by getline
        std::cin.ignore(1, '\n');

        switch (option)
        {
        case 1:
            delete_item(shopping_list);
            break;
        case 2:
            add_item(shopping_list);
            break;
        case 3:
            append_item(shopping_list);
            break;
        case 4:
            display(shopping_list);
            break;
        }

        if (option < 1 || option > 5)
        {
            std::cerr << "\nInvalid option: " << option << "\n";
            option = 5;
        }

    } while (option != 5);

    return (0);
}