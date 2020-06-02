#include <iostream>

class Shape
{
public:
    double x, y;
    void get_data(double x, double y = 0)
    {
        this->x = x;
        this->y = y;
    }
    virtual void display_area() {}
};

class Triangle : public Shape
{
public:
    void display_area()
    {
        float area = 0.5 * x * y;
        std::cout << "Area of triangle: " << area << "\n";
    }
};

class Rectangle : public Shape
{
public:
    void display_area()
    {
        float area = x * y;
        std::cout << "Area of rectangle: " << area << "\n";
    }
};

void getDimentions(int &x, int &y)
{
    std::cout << "ENTER DIMENTIONS:\n";
    std::cout << "Enter value for x: ";
    std::cin >> x;
    std::cout << "Enter value for y: ";
    std::cin >> y;
}

int main()
{
    int x, y;
    Shape *shape;

    getDimentions(x, y);
    Rectangle rect;
    shape = &rect;
    shape->get_data(x, y);
    shape->display_area();

    getDimentions(x, y);
    Triangle tri;
    shape = &tri;
    shape->get_data(x, y);
    shape->display_area();

    return EXIT_SUCCESS;
}