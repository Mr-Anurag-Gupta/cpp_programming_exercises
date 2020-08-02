#include <iostream>
#include <cmath>

using std::cout, std::endl;

class Polar
{
    float radius;
    float angle;

public:
    Polar() : radius(0.0f), angle(0.0f){};
    Polar(float r, float a) : radius(r), angle(a){};
    Polar(int, int);
    float convertToX(float);
    float convertToY(float);
    float convertToAngle(float, float);
    float convertToRadius(float, float);
    Polar operator+(Polar &);
    void display();
};

Polar::Polar(int x, int y)
{
    this->radius = sqrtf(x * x + y * y);
    this->angle = atan(y / x);
}

float Polar::convertToX(float radius)
{
    return radius * cos(angle);
}

float Polar::convertToY(float angle)
{
    return radius * sin(angle);
}

float Polar::convertToAngle(float x, float y)
{
    return atan(y / x);
}

float Polar::convertToRadius(float x, float y)
{
    return sqrtf(x * x + y * y);
}

Polar Polar::operator+(Polar &point)
{
    float x = this->convertToX(this->radius) + point.convertToX(point.radius);
    float y = this->convertToY(this->angle) + point.convertToY(point.angle);
    return Polar(x, y);
}

void Polar::display()
{
    cout << endl;
    cout << "r = " << this->radius << endl;
    cout << "a = " << this->angle << endl;
}

int main()
{
    Polar p1(12, 43);
    Polar p2(34, 21);
    Polar p3 = p1 + p2;

    p1.display();
    p2.display();
    p3.display();

    return EXIT_SUCCESS;
}