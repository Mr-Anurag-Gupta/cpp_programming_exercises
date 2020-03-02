/*
 *
*/

#include <iostream>

class FLOAT
{
    float mFloat;

public:
    FLOAT() { mFloat = 0.0; }
    FLOAT(float mFloat) { this->mFloat = mFloat; }
    void display() { std::cout << mFloat << std::endl; };

    // Overloads FLOAT <op> FLOAT
    FLOAT operator+(FLOAT &);
    FLOAT operator*(FLOAT &);
    FLOAT operator-(FLOAT &);
    FLOAT operator/(FLOAT &);

    // Overloads either Float <op> <builtin type>
    // or <builtin Type> <op> Float
    friend FLOAT operator+(FLOAT &, float);
    friend FLOAT operator+(float, FLOAT &);
    friend FLOAT operator*(FLOAT &, float);
    friend FLOAT operator*(float, FLOAT &);
    friend FLOAT operator-(FLOAT &, float);
    friend FLOAT operator-(float, FLOAT &);
    friend FLOAT operator/(FLOAT &, float);
    friend FLOAT operator/(float, FLOAT &);
};

int main()
{
    FLOAT f1(1.2f), f2(3.6f);
    std::cout << "f1: ";
    f1.display();
    std::cout << "f2: ";
    f2.display();

    FLOAT f3 = f1 + f2;
    std::cout << "f3: ";
    f3.display();

    FLOAT f4 = 2.4f + f1;
    std::cout << "f4: ";
    f4.display();

    FLOAT f5 = f1 / 2.0f;
    std::cout << "f5: ";
    f5.display();

    FLOAT f6 = f1 * 0.2f;
    std::cout << "f6: ";
    f6.display();

    return EXIT_SUCCESS;
}

// Member functions.
FLOAT FLOAT::operator+(FLOAT &obj)
{
    return FLOAT(mFloat + obj.mFloat);
}

FLOAT FLOAT::operator*(FLOAT &obj)
{
    return FLOAT(mFloat * obj.mFloat);
}

FLOAT FLOAT::operator-(FLOAT &obj)
{
    return FLOAT(mFloat - obj.mFloat);
}

FLOAT FLOAT::operator/(FLOAT &obj)
{
    return FLOAT(mFloat / obj.mFloat);
}

// Friend functions.
FLOAT operator+(FLOAT &obj, float fval)
{
    return FLOAT(obj.mFloat + fval);
}

FLOAT operator+(float fval, FLOAT &obj)
{
    return FLOAT(fval + obj.mFloat);
}

FLOAT operator*(FLOAT &obj, float fval)
{
    return FLOAT(obj.mFloat * fval);
}

FLOAT operator*(float fval, FLOAT &obj)
{
    return FLOAT(fval * obj.mFloat);
}

FLOAT operator-(FLOAT &obj, float fval)
{
    return FLOAT(obj.mFloat - fval);
}

FLOAT operator-(float fval, FLOAT &obj)
{
    return FLOAT(fval - obj.mFloat);
}

FLOAT operator/(FLOAT &obj, float fval)
{
    return FLOAT(obj.mFloat / fval);
}

FLOAT operator/(float fval, FLOAT &obj)
{
    return FLOAT(fval / obj.mFloat);
}
