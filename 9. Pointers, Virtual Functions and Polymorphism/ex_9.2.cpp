#include <iostream>

class Shape
{
public:
    int x, y;
    void get_data(int x, int y = 0)
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
        std::cout << "Area of rectangle: " << area << "\n";
    }
};

class Rectangle : public Shape
{
public:
    void display_area()
    {
        float area = x * y;
        std::cout << "Area of triangle: " << area << "\n";
    }
};

class Circle : public Shape
{
public:
    void display_area()
    {
        float area = 3.14 * x * x;
        std::cout << "Area of circle: " << area << "\n";
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

    std::cout << "\n______Rectangle______\n";
    getDimentions(x, y);
    Rectangle rect;
    shape = &rect;
    shape->get_data(x, y);
    shape->display_area();

    std::cout << "\n______Triangle______\n";
    getDimentions(x, y);
    Triangle tri;
    shape = &tri;
    shape->get_data(x, y);
    shape->display_area();

    std::cout << "\n________Cirle________\n";
    getDimentions(x, y);
    Circle cir;
    shape = &cir;
    shape->get_data(x);
    shape->display_area();

    std::cout << "\n";
    return EXIT_SUCCESS;
}