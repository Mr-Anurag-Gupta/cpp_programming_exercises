/*
 * A books shop maintains the inventory of books that are being sold at the shop.
 * The list includes details such as author, title, price, publisher andd stock
 * position. Wheneuer a customer wants a book, the sales person inputs the title and
 * author and the system searches the list and displays whether it available or not.
 * if it is not, an appropriate message is displayed. If it is, then the system 
 * displays the book details and request for the number of copies required. If the 
 * requested copies are available, the total cost of the requested copies is 
 * displayed; otherwise the message "Required copies not in stock" is displayed.
 * Design a system using a class called books with suitable member functions and
 * constructors. Use new operator in constructors to allocate memory space required.
*/

#include <iostream>
#include <iomanip>
#include <ios>    // Use to get streamsize
#include <limits> // Use to get numeric_limits

const int BUF_SIZE = 4;

class Books
{
    char *author, *title, *publisher;
    float price;
    int stock;

public:
    Books();
    ~Books();
    bool search(const char *, const char *);
    void buy();
    void add(const char *, const char *, const char *, float, int);
    void showDetails();
};

Books::Books()
{
    author = new char[30];
    title = new char[50];
    publisher = new char[50];
    price = 0.0f;
    stock = 0;
}

Books::~Books()
{
    delete title;
    delete author;
    delete publisher;
}

inline bool Books::search(const char *title, const char *author)
{
    if (strcmp(title, this->title) == 0 && strcmp(author, this->author) == 0)
        return 1;
    return 0;
}

void Books::buy()
{
    showDetails();

    int copies;
    std::cout << "No. of copies required: ";
    std::cin >> copies;
    if (stock >= copies)
    {
        std::cout << "Total bill amount: Rs. " << copies * price << std::endl;
        std::cout << "Transaction is successful" << std::endl;
        stock -= copies;
    }
    else
        std::cout << "Required copies not in stock" << std::endl;
}

void Books::add(const char *title, const char *author, const char *publisher, float price, int stock)
{
    strcpy(this->title, title);
    strcpy(this->author, author);
    strcpy(this->publisher, publisher);
    this->price = price;
    this->stock = stock;
}

void Books::showDetails()
{
    std::cout << "\nBook Details:" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << std::setw(10) << "Title:"
              << std::setw(25) << title << std::endl;
    std::cout << std::setw(10) << "Author:"
              << std::setw(25) << author << std::endl;
    std::cout << std::setw(10) << "Publisher:"
              << std::setw(25) << publisher << std::endl;
    std::cout << std::setw(10) << "Price:"
              << std::setw(25) << price << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
}

void iniStoreWithDummyData(Books *);
void processOptions(int choice, Books *, bool &);

int main()
{
    // Dummy book store.
    Books *books = new Books[4];
    iniStoreWithDummyData(books);

    int choice;
    bool loop = true;
    do
    {
        std::cout << "\n--------------------- Book Store ---------------------" << std::endl;
        std::cout << "\n\t\t1. search and buy a book" << std::endl;
        std::cout << "\t\t2. exit" << std::endl;
        std::cout << "\n\tYour choice: ";
        std::cin >> choice;
        // clear the buffer.
        std::cin.ignore(CHAR_MAX, '\n');

        processOptions(choice, books, loop);

    } while (loop);
    return EXIT_SUCCESS;
}

void iniStoreWithDummyData(Books *books)
{
    books[0].add("HowTo: James Bond", "James Bond", "Hollywood", 220.99f, 5);
    books[1].add("Titanic", "James Cameron", "MagrawHills", 250.3f, 3);
    books[2].add("Stay Hungry, Stay Foolish", "Paul cohilo", "Western Society", 140.2f, 7);
    books[3].add("HowTo: Run a Business", "Rocky J", "Junoon", 130.4f, 3);
}

void processOptions(int choice, Books *books, bool &loop)
{
    char title[30] = {'\0'}, author[20] = {'\0'};
    bool isFound = false;
    switch (choice)
    {
    case 1:
        //  Get the details.
        std::cout << "\nEnter title: ";
        std::cin.getline(title, 30);
        std::cout << "Enter author: ";
        std::cin.sync();
        std::cin.getline(author, 20);

        // std::cout << "\n\tTitle: " << title;
        // std::cout << "\n\tAuthor: " << author;

        for (auto i = 0; i < BUF_SIZE; i++)
        {
            if (books[i].search(title, author))
            {
                books[i].buy();
                isFound = true;
                break;
            }
        }

        if (!isFound)
            std::cout << "\n"
                      << title << " is unavailable." << std::endl;

        break;
    case 2:
        loop = false;
        break;
    default:
        std::cout << "\nInvalid input!" << std::endl;
        std::cout << "Try again...\n"
                  << std::endl;
        break;
    }
}