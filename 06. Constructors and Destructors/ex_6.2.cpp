/*
 * Define a string class that could work as a user-defined string type.
*/

#include <iostream>
#include <string.h>

class String
{
    char *name;
    int length;

public:
    String();
    String(const char *);
    void join(String &, String &);
    void display() { std::cout << name << "\n"; }
};

String::String()
{
    length = 0;
    name = new char[length];
}

String::String(const char *str)
{
    length = strlen(str);
    delete name;

    name = new char[length + 1];
    strcpy(name, str);
}

void String::join(String &s1, String &s2)
{
    length = s1.length + s2.length;
    delete name;

    name = new char[length + 1];

    strcpy(name, s1.name);
    strcat(name, s2.name);
}

int main()
{
    String s1;
    s1.display();

    String s2("Well done!");
    s2.display();

    String s3("You did it");
    s3.display();

    String s4;
    s4.join(s2, s3);
    s4.display();

    String s5;
    s5 = s2;
    s5.display();

    return EXIT_SUCCESS;
}