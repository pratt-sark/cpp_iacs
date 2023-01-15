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
    Rectangle()
    {
        this->length = 0;
        this->breadth = 0;
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
    void input()
    {
        cout<<"\nEnter length and breadth of rectangle:\n";
        cin>>length>>breadth;
    }
};

class Circle : public Shape
{
    double radius;

public:
    Circle()
    {
        this->radius = 0;
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
    void input()
    {
        cout<<"\nEnter radius of circle:\n";
        cin>>radius;
    }
};

class Triangle : public Shape
{
    double side1, side2, side3;

    public:
    Triangle()
    {
        this->side1 = this->side2 = this->side3 = 0;
    }
    void input()
    {
        cout<<"\nEnter 3 sides of the triangle:\n";
        cin>>side1>>side2>>side3;
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

class ShapeNotSupported : public exception
{
    public:
    string message;
    ShapeNotSupported(string s)
    {
        this->message = s;
    }
    ShapeNotSupported()
    {
        this->message = "ShapeNotSupported Exception";
    }
};

class ShapeCreator : public Shape
{
    public:
    Shape *create(string name)
    {
        Shape* shape;
        if(name=="rectangle")
        {
            Rectangle* r = new Rectangle();
            r->input();
            shape = r;
        }
        else if(name=="circle")
        {
            Circle* c = new Circle();
            c->input();
            shape = c; 
        }
        else if (name=="triangle")
        {
            Triangle* t = new Triangle();
            t->input();
            shape = t;
        }
        else
        {
            shape = NULL;
        }
        return shape;
    }
};

int main()
{
    string name;
    cout<<"\n\n================Enter shape name================\n";
    cin>>name;
    Shape* shape;

    try
    {
        ShapeCreator* creator;
        shape = creator->create(name);
        if (shape == NULL)
            throw new ShapeNotSupported();
        cout<<"\n\nDisplaying "<<name<<" properties...."<<endl;
    }
    catch(ShapeNotSupported& e)
    {
        std::cerr << e.message << '\n';
    }
    compute(shape);
}