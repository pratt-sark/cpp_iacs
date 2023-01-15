#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual double getPerimeter() = 0;
    virtual double getArea() = 0;
};

class Rectangle : public Shape
{
    double length;
    double breadth;

public:
    Rectangle(double length, double breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }
    void setLength(double value)
    {
        length = value;
    }
    void setBreadth(double value)
    {
        breadth = value;
    }
    double getArea()
    {
        return length * breadth;
    }
    double getPerimeter()
    {
        return 2 * (length + breadth);
    }
};

class Circle : public Shape
{
    double radius;

public:
    Circle(double radius)
    {
        this->radius = radius;
    }
    void setRadius(double value)
    {
        radius = value;
    }
    double getPerimeter()
    {
        return radius * 2 * (22.0 / 7);
    }
    double getArea()
    {
        return radius * radius * (22.0 / 7);
    }
};

class Triangle : public Shape
{
    double side1, side2, side3;

    public:
    Triangle(double a, double b, double c)
    {
        this->side1 = a;
        this->side2 = b;
        this->side3 = c;
    }
    void setSides(double v1, double v2, double v3)
    {
        side1 = v1;
        side2 = v2;
        side3 = v3;
    }
    double getArea()
    {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    double getPerimeter()
    {
        return side1 + side2 + side3;
    }
};

void compute(Shape *shape)
{
    cout << "\nArea = " << shape->getArea();
    cout << "\nPerimeter = " << shape->getPerimeter()<<endl;
}

int main()
{
    double x, y, z;
    cout << "\nEnter length and breadth of rectangle: " << endl;
    cin >> x >> y;
    Shape *shape = new Rectangle(x, y);
    cout << "\n----RECTANGLE----" << endl;
    compute(shape);

    cout << "\nEnter radius of circle: " << endl;
    cin >> x;
    shape = new Circle(x);
    cout << "\n----CIRCLE----" << endl;
    compute(shape);

    cout << "\nEnter 3 sides of triangle: " << endl;
    cin >> x >> y >> z;
    shape = new Triangle(x, y, z);
    cout << "\n----TRIANGLE----" << endl;
    compute(shape);
    return 0;
}