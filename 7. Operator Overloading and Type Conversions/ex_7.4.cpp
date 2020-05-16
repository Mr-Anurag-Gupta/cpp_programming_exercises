
#include <iostream>
#include <cstdlib>

class String
{
private:
    char *str;
    int length;

public:
    String()
    {
        str = nullptr;
        length = 0;
    }
    String(const char *s)
    {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    char *getString() { return str; }
    int getLength() { return length; }
    void display() { std::cout << str << std::endl; }

    // Overloaded operators.
    friend String operator+(String &, String &);
    friend bool operator==(String &, String &);
    friend String operator+(String &, const char *);
    friend String operator+(const char *, String &);
};

int main()
{
    String s1("James");
    s1.display();
    String s2("Bond");
    s2.display();

    String s3 = s1 + s2;
    s3.display();

    String s4 = "I am " + s1;
    s4.display();

    String s5 = s3 + " is a MI6 agent.";
    s5.display();

    String s6("Bond");
    bool isEqual = (s2 == s6);
    std::cout << "Is s2 == s6? " << isEqual << std::endl;

    return EXIT_SUCCESS;
}

bool operator==(String &s1, String &s2)
{
    if (strcmp(s1.str, s2.str) == 0)
        return 1;
    return 0;
}

String operator+(String &s1, String &s2)
{
    String s3;
    s3.length = s1.length + s2.length;
    s3.str = new char[s3.length + 1];
    strcpy(s3.str, s1.str);
    strcat(s3.str, s2.str);
    return s3;
}

String operator+(String &s1, const char *s2)
{
    String s3;
    s3.length = s1.length + strlen(s2);
    s3.str = new char[s3.length + 1];
    strcpy(s3.str, s1.str);
    strcat(s3.str, s2);
    return s3;
}

String operator+(const char *s1, String &s2)
{
    String s3;
    s3.length = strlen(s1) + s2.length;
    s3.str = new char[s3.length + 1];
    strcpy(s3.str, s1);
    strcat(s3.str, s2.str);
    return s3;
}