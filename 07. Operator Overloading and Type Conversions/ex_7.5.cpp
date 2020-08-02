#include <iostream>
#include <cmath>

using std::cout, std::cin, std::endl;

class Rectangle;

class Polar
{
    float radius;
    float angle;

private:
    float convertToX();
    float convertToY();
    float convertToAngle();
    float convertToRadius();

public:
    Polar() : radius(0.0f), angle(0.0f){};
    Polar(float r, float a) : radius(r), angle(a){};
    Polar(int, int);
    float getX() { return this->convertToX(); };
    float getY() { return this->convertToY(); };
    float getAngle() { return this->angle; };
    float getRadius() { return this->radius; };
    void display();
    Polar operator+(Polar &);
    operator Rectangle();
};

Polar::Polar(int x, int y)
{
    this->radius = sqrtf(x * x + y * y);
    this->angle = atan(y / x);
}

float Polar::convertToX()
{
    return radius * cos(angle);
}

float Polar::convertToY()
{
    return radius * sin(angle);
}

float Polar::convertToAngle()
{
    return atan(getY() / getX());
}

float Polar::convertToRadius()
{
    float x = getX();
    float y = getY();
    return sqrtf(x * x + y * y);
}

Polar Polar::operator+(Polar &point)
{
    return Polar((getX() + point.getX()), (getY() + point.getY()));
}

void Polar::display()
{
    cout << endl;
    cout << "r = " << this->radius << ", "
         << "a = " << this->angle << endl;
}

class Rectangle
{
    int x, y;

public:
    // Constructors
    Rectangle() : x(0), y(0){};
    Rectangle(int x, int y) : x(x), y(y){};

    // Getters & setters for x-axis.
    int getX() { return this->x; };
    int getY() { return this->y; };

    // Getters & setters for y-axis.
    void setX(int value) { this->x = value; };
    void setY(int value) { this->y = value; };

    // Casting operator.
    operator Polar() { return Polar(this->getX(), this->getY()); };

    void display();
};

void Rectangle::display()
{
    cout << endl;
    cout << "x = " << getX() << ", "
         << "y = " << getY() << endl;
}

Polar::operator Rectangle()
{
    return Rectangle(this->getX(), this->getY());
}

int main()
{
    Polar p1(12, 32);
    Rectangle r1 = p1;

    p1.display();
    r1.display();

    return EXIT_SUCCESS;
}