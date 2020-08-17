/**
 * Write a program that reads the name
 *      Martin Luther King
 * from the keyboard into three separate string objects and
 * then concatenates them into a new string object using
 * (a) + operator and 
 * (b) append() function
*/
#include <iostream>
#include <string>

int main()
{
    std::string s1, s2, s3;

    std::cin >> s1;
    std::cin >> s2;
    std::cin >> s3;

    std::cout << "\nUsing + operator: ";
    std::string s4;
    s4 = s1 + " " + s2 + " " + s3;
    std::cout << s4;

    std::cout << "\n\nUsing append() function: ";
    std::string s5;
    s5.append(s1);
    s5.append(" ");
    s5.append(s2);
    s5.append(" ");
    s5.append(s3);
    std::cout << s5 << "\n\n";

    return (0);
}