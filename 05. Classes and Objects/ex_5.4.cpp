/*
 * Modify the class and program of Exercise 5.2 such that the program would be
 * able to add two vectors and display the resultant vector. (Note that we can
 * pass objects as function arguments.)
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
    int getSize() { return size; };
    float valueAtIndex(int index) { return v[index]; };
    void multiplyByScalar(int);
    void addVector(Vector);
    void display();
};

void Vector::createVector(float arr[], int size)
{
    this->size = size;
    v = new float[size];

    for (auto i = 0; i < size; i++)
        v[i] = arr[i];
}

void Vector::addVector(Vector v1)
{
    for (auto i = 0; i < size; i++)
    {
        v[i] += v1.valueAtIndex(i);
    }
    display();
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
    Vector vec2;

    std::cout << "\nCreating a vector.\n";
    vec.createVector(a, 4);
    vec.display();

    vec2.createVector(a, size);
    vec.addVector(vec2);

    std::cout << std::endl;

    return EXIT_SUCCESS;
}