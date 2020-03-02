/*
 * Improve the system design in Exercise 6.3 to incorporate the folWwing features:
 *   (a) The price of the books should be updated as and when required.Use a private
 *       member function to implement this.
 *   (b) The stock value of each book •hordd be automatically updated M soon as a
 *       transaction is completed.
 *   (c) The number of successful and unsuccessful transactions should be recorckd
 *       for the purpose of statistical analysis. Use static data members to keep 
 *       count of transactions.
*/

#include <iostream>
#include <iomanip>

const int BUF_SIZE = 4;

enum OPTIONS
{
    SEARCH = 1,
    BUY,
    EDIT,
    EXIT,
};

/***************************************
 * Class Books
****************************************/
class Books
{
    static int transactionSucceeded;
    static int transactionFailed;
    char *author, *title, *publisher;
    float price;
    int stock;

public:
    Books();
    ~Books();
    bool search(const char *, const char *);
    void buy();
    void edit();
    void add(const char *, const char *, const char *, float, int);
    void showDetails();
};

/***************************************
 * Local Functions
****************************************/
void iniStoreWithDummyData(Books *);
void getDetails(char *, char *);
void processOptions(int choice, Books *, bool &);

int Books::transactionSucceeded = 0;
int Books::transactionFailed = 0;

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
        std::cout << "\n\t\t1. search a book";
        std::cout << "\n\t\t2. Buy a book";
        std::cout << "\n\t\t3. Update price";
        std::cout << "\n\t\t4. exit" << std::endl;
        std::cout << "\n\tYour choice: ";
        std::cin >> choice;
        // clear the buffer.
        std::cin.ignore(CHAR_MAX, '\n');

        processOptions(choice, books, loop);

    } while (loop);
    return EXIT_SUCCESS;
}

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
    int copies;

    this->showDetails();

    std::cout << "\nNo. of copies required: ";
    std::cin >> copies;
    if (stock >= copies)
    {
        std::cout << "\nTotal bill amount: Rs. " << copies * price << std::endl;
        std::cout << "Transaction is successful" << std::endl;

        // Update succeeded transaction count;
        Books::transactionSucceeded++;
        stock -= copies;
    }
    else
    {
        std::cout << "Required copies not in stock" << std::endl;
        // Update failed transaction count;
        Books::transactionFailed++;
    }
}

void Books::edit()
{
    std::cout << "\nEnter new price: ";
    std::cin >> price;
    std::cin.sync();
    std::cout << "Price updated successfully" << std::endl;
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

void iniStoreWithDummyData(Books *books)
{
    books[0].add("HowTo: James Bond", "James Bond", "Hollywood", 220.99f, 5);
    books[1].add("Titanic", "James Cameron", "MagrawHills", 250.3f, 3);
    books[2].add("Stay Hungry, Stay Foolish", "Paul cohilo", "Western Society", 140.2f, 7);
    books[3].add("HowTo: Run a Business", "Rocky J", "Junoon", 130.4f, 3);
}

void getDetails(char *title, char *author)
{
    std::cout << "\nEnter title: ";
    std::cin.getline(title, 30);
    std::cout << "Enter author: ";
    std::cin.sync();
    std::cin.getline(author, 20);
}

int getDetailsAndSetFlags(Books *books, char *title, char *author, bool &isFound)
{
    int i;

    //  Get the details.
    getDetails(title, author);

    for (i = 0; i < BUF_SIZE; i++)
    {
        if (books[i].search(title, author))
        {
            isFound = true;
            break;
        }
    }

    if (!isFound)
        return -1;
    return i;
}

void processOptions(int choice, Books *books, bool &loop)
{
    char title[30] = {'\0'}, author[20] = {'\0'};
    bool isFound = false;
    int i;

    switch (choice)
    {
    case SEARCH:
        i = getDetailsAndSetFlags(books, title, author, isFound);
        if (i == -1)
            std::cout << "\nStatus: " << title << " is unavailable." << std::endl;
        else
            std::cout << "\nStatus: " << title << " is available." << std::endl;
        break;
    case BUY:
        i = getDetailsAndSetFlags(books, title, author, isFound);
        if (i == -1)
            std::cout << "\nStatus: " << title << " is unavailable." << std::endl;
        else
            books[i].buy();
        break;
    case EDIT:
        i = getDetailsAndSetFlags(books, title, author, isFound);
        if (i == -1)
            std::cout << "\nStatus: " << title << " is unavailable." << std::endl;
        else
            books[i].edit();
        break;
    case EXIT:
        std::cout << '\n';
        loop = false;
        break;
    default:
        std::cout << "\nInvalid input!" << std::endl;
        std::cout << "Try again..."
                  << std::endl;
        break;
    }
}