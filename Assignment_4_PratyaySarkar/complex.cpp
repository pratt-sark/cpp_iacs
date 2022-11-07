//Program : 2
//Pratyay Sarkar

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//Class representing a Complex number
class Complex
{
    double x; //real part
    double y; //complex part

    public:
    void add (Complex,Complex);
    void subtract (Complex,Complex);
    void mult (Complex,Complex);
    void divide (Complex,Complex);
    void display();
    void input();
    Complex()
    {
        this->x = 0.0;
        this->y = 0.0;
    }
    Complex(double x,double y)
    {
        this->x = x;
        this->y = y;
    }
    Complex(double x)
    {
        this->x = x;
        this->y = 0;
    }
};

//add two complex numbers
void Complex :: add (const Complex A, const Complex B)
{
    this->x = A.x + B.x; //add the real parts, this forms real part of the result
    this->y = A.y + B.y; //add the complex parts, this forms complex part of the result
}

//subtract one complex number from another
void Complex :: subtract (Complex A, Complex B)
{
    this->x = A.x - B.x; //add the real parts, this forms real part of the result
    this->y = A.y - B.y; //add the complex parts, this forms complex part of the result
}

//multiply two complex numbers
void Complex :: mult (Complex A, Complex B)
{
    //real part of the result, the x parts are already real, and
    this->x = A.x*B.x - A.y*B.y; //multiplying two complex parts gives the minus sign
    //complex part, multiplying real parts with complex parts
    this->y = A.y*B.x + B.y*A.x; // gives the complex part of the resultant complex number
}

//divide one complex number by another
void Complex :: divide (Complex A, Complex B)
{
    //************division code goes here***********
    double div = B.y*B.y + B.x*B.x;
    this->x = (A.x*B.x+A.y*B.y)/div;
    this->y = (A.y*B.x-A.x*B.y)/div;
}

//Display a Complex number in proper format
void Complex :: display()
{
    cout<<this->x; //print the real part of the complex number
    if(this->y==0) //if there's no complex part, dont do anything and return
        return;
    else if(this->y<0) //if the complex part is negative, print a minus sign
        cout<<" -";
    else //if the complex part is positive, print a plus sign
        cout<<" +";
    cout<<fabs(this->y)<<" i"; //now print the absolute value of the complex part
}

void Complex :: input()
{
    cout<<"\n\nEnter the Complex number: ";
    cout<<"\nReal Part = ";
    cin>>this->x;
    cout<<"Complex Part = ";
    cin>>this->y;
}

int main()
{
    Complex A,B,sum,difference,product,quotient;
    A.input();
    B.input();

    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\nThe Complex Number (A) = ";
    A.display();
    cout<<"\nThe Complex Number (B) = ";
    B.display();

    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\nThe Complex Number (A+B) [Sum] = ";
    sum.add(A, B); //call the sum function
    sum.display(); 

    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\nThe Complex Number (A-B) [Difference] = ";
    difference.subtract(A, B); //call the subtract function
    difference.display(); 

    cout<<"\nThe Complex Number (A*B) [Product] = ";
    product.mult(A, B); //call the product function
    product.display();
    cout<<"\n-------------------------------------------------------------\n";

    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\nThe Complex Number (A/B) [Quotient] = ";
    quotient.divide(A, B); //call the divide function
    quotient.display(); 

    cout<<"\n--------EXAMPLES TO DEMONSTRATE that these functions accept real values as well-------\n";
    sum.add(A,3);
    cout<<"\nAfter adding a real number to A, we get: ";
    sum.display();
    product.mult(5,B);
    cout<<"\nAfter multiplying a real number to B, we get: ";
    product.display();
    cout<<"\n-------------------------------------------------------------\n";
    return 0;
}