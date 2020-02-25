/*
 * Write a class to represent a vector (a series of float value). Include member
 * functions to perform the following tasks:
 * (a) To create the vector
 * (b) To modify the value of a given element
 * (c) To multiply by a scalar value
 * (d) To display the vector in the form (10, 20, 30, ...)
*/

#include <iostream>
#include <string>
#include <cassert>

class Vector
{
    float *v;
    int size;

public:
    Vector()
    {
        v = nullptr;
        size = 0;
    }
    void createVector(float[], int);
    void update(int, float);
    void multiplyByScalar(int);
    void display();
};

void Vector::createVector(float arr[], int size)
{
    this->size = size;
    v = new float[size];

    for (auto i = 0; i < size; i++)
        v[i] = arr[i];
}

inline void Vector::update(int elemIndex, float value)
{
    assert(v != nullptr);
    v[elemIndex] = value;
}

void Vector::multiplyByScalar(int value)
{
    assert(v != nullptr);
    for (auto i = 0; i < size; i++)
        v[i] *= value;
}

void Vector::display()
{
    assert(v != nullptr);
    for (auto i = 0; i < size; i++)
        std::cout << v[i] << ' ';
    std::cout << std::endl;
}

int main()
{
    float a[] = {1.2, 4.3, 2.2, 5.2, 7.6};
    int size = sizeof(a) / sizeof(a[0]);

    Vector vec;

    std::cout << "\nCreating a vector.\n";
    vec.createVector(a, 4);
    vec.display();

    std::cout << "\nUpdating an element in the vector.\n";
    vec.update(3, 8.44);
    vec.display();

    std::cout << "\nMultiplying by an scalar value.\n";
    vec.multiplyByScalar(3);
    vec.display();

    std::cout << std::endl;

    return EXIT_SUCCESS;
}