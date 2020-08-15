/**
 * Create a Student class that includes a student's first name and 
 * the roll number. Create five objects of this class and store them
 * in a list thus creating a phone_list. Write a program using this 
 * list to display the student name if the roll number is given and
 * vice versa.
*/

#include <iostream>
#include <string>
#include <list>

class Student
{
    std::string m_name;
    short int m_roll_number;

public:
    Student(std::string name, short int roll_number) : m_name(name), m_roll_number(roll_number) {}
    std::string get_name() const
    {
        return m_name;
    }
    short int get_roll_number() const
    {
        return m_roll_number;
    }
};

void display(std::list<Student> lst)
{
    for (auto it : lst)
    {
        std::cout << it.get_name() << " " << it.get_roll_number() << '\n';
    }
}

void find_student_by_roll_number(const std::list<Student> &phone_list, short int target_value)
{
    bool is_found = false;

    std::list<Student>::const_iterator It = phone_list.cbegin();
    for (; It != phone_list.cend(); It++)
    {
        if (It->get_roll_number() == target_value)
        {
            std::cout << "\nStudent associated with roll number "
                      << target_value << " is " << It->get_name() << '\n';
            is_found = true;
            break;
        }
    }

    if (!is_found)
    {
        std::cout << "\nNo student found with roll number " << target_value << '\n';
    }
}

void find_student_by_name(const std::list<Student> &phone_list, std::string target_value)
{
    bool is_found = false;

    std::list<Student>::const_iterator It = phone_list.cbegin();
    for (; It != phone_list.cend(); It++)
    {
        if (It->get_name() == target_value)
        {
            std::cout << "\nStudent " << target_value << " has roll number "
                      << It->get_roll_number() << '\n';
            is_found = true;
            break;
        }
    }

    if (!is_found)
    {
        std::cout << "\nNo student found with name " << target_value << '\n';
    }
}

int main()
{
    std::list<Student> phone_list;

    // Insert the 5 objects into phone_list.
    phone_list.push_front(Student("James", 01));
    phone_list.push_front(Student("John", 02));
    phone_list.push_front(Student("Jonny", 03));
    phone_list.push_front(Student("Jay", 04));
    phone_list.push_front(Student("Javed", 05));

    short int choice = 3;
    std::string name;

    do
    {
        std::cout << "\nENTER THE CHOICE (1, 2, or 3):\n"
                  << "1) Find student by roll number\n"
                  << "2) Find student by name\n"
                  << "3) Exit\n\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            short int roll_num;
            std::cout << "\nEnter roll number of the student: ";
            std::cin >> roll_num;
            find_student_by_roll_number(phone_list, roll_num);
            break;
        case 2:
            std::cout << "\nEnter name of the student: ";
            std::cin >> name;
            find_student_by_name(phone_list, name);
            break;
        case 3:
            std::cout << "\nThank You!\n\n";
            break;
        }

        if (choice < 1 || choice > 3)
        {
            std::cerr << "\nInvalid choice: " << choice << "\n\n";
            choice = 3;
        }

    } while (choice != 3);

    return (0);
}