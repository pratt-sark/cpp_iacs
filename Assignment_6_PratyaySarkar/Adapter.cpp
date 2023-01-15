#include <iostream>
#include <cmath>
#include <ctime>
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
    Rectangle()
    {
        length = breadth = 0;
        srand((unsigned)time(0));
        length = rand() % 100;

        do
        {
            breadth = rand() % 100;
        }while(length <= breadth);
    }
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
    Circle()
    {
        srand((unsigned)time(0));
        radius = rand() % 100;
    }
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
    Triangle()
    {
        srand((unsigned)time(0));
        side1 = rand() % 100;
        side2 = rand() % 100;
        side3 = rand() % 100;
    }
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

typedef Shape Figure;
typedef Rectangle RectangularFigure;
typedef Circle CircularFigure;

void printArea(Figure *f)
{
    cout << "Area = " << f->getArea() << endl;
}

int main()
{
    Figure *f1 = new RectangularFigure();
    Figure *f2 = new CircularFigure();
    printArea(f1);
    printArea(f2);
}