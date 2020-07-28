/**
 * Write a class template to represent a generic vector. Include member functions to 
 * perform the following tasks.
 * (a) To create the vector.
 * (b) To modify the value of a given element.
 * (c) To multiply by a scalar value.
 * (d) To display the vector in the form (10, 20, 30, ...).
*/

#include <iostream>

const int size = 3;

template <class T>
class vector
{
private:
    T *v;

public:
    vector()
    {
        v = new T[size];
        for (int i = 0; i < size; i++)
        {
            v[i] = 0;
        }
    }
    T &operator[](int index)
    {
        return v[index];
    }
    void operator*(int value)
    {
        for (int i = 0; i < size; i++)
            v[i] = v[i] * value;
    }
    void display(void)
    {
        std::cout << "(";
        for (int i = 0; i < size; i++)
        {
            if (i == size - 1)
                std::cout << this->v[i] << ")\n";
            else
                std::cout << this->v[i] << ", ";
        }
    }
};

int main(int argc, char *argv[])
{
    // Create vector.
    vector<int> vec;
    vec.display();

    // Modify value of a given element.
    vec[1] = 2;
    vec.display();

    // Multiply by scalar.
    vec * 2;
    vec.display();

    return EXIT_SUCCESS;
}