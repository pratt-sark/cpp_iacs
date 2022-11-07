//Program : 1
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
    //add two complex numbers
    Complex operator + (const Complex B)
    {
        Complex C;
        C.x = B.x + x; //add the real parts, this forms real part of the result
        C.y = B.y + y; //add the complex parts, this forms complex part of the result
        return C;
    }
    //subtract one complex number from another
    Complex operator - (const Complex B)
    {
        Complex C;
        C.x = x - B.x; //add the real parts, this forms real part of the result
        C.y = y - B.y; //add the complex parts, this forms complex part of the result
        return C;
    }

    //multiply two complex numbers
    Complex operator * (const Complex B)
    {
        Complex C;
        //real part of the result, the x parts are already real, and
        C.x = x*B.x - y*B.y; //multiplying two complex parts gives the minus sign
        //complex part, multiplying real parts with complex parts
        C.y = y*B.x + B.y*x; // gives the complex part of the resultant complex number
        return C;
    }
    friend bool operator > (const Complex, const Complex);
    void display();
    void input();
    Complex() //default constructor
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

bool operator > (const Complex A, const Complex B)
{
    return (A.y==0 && B.y==0 && A.x>B.x);
}

int main()
{
    Complex A,B,sum,difference,product;
    A.input();
    B.input();

    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\nThe Complex Number (A) = ";
    A.display();
    cout<<"\nThe Complex Number (B) = ";
    B.display();

    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\nThe Complex Number (A+B) [Sum] = ";
    sum = A+B; //do sum
    sum.display(); 

    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\nThe Complex Number (A-B) [Difference] = ";
    difference = A-B; //do subtraction
    difference.display(); 

    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\nThe Complex Number (A*B) [Product] = ";
    product = A*B; //do product
    product.display();
    cout<<"\n-------------------------------------------------------------\n";
    cout<<"\nA>B has returned "<<((A>B)?"true.":"false.")<<endl;
    cout<<"\n-------------------------------------------------------------\n";

    return 0;
}