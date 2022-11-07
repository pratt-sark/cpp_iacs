//Program : 3
//Pratyay Sarkar

#include <iostream>
using namespace std;

class IntObject
{
    int value; //Value of the int object
    public:
        IntObject(int value) //contructor for initialising IntObject
        {
            this->value = value;
        }
        int operator ! () //IntObject to int
        {
            return value;
        }
        void display() //display the IntObject
        {
            cout<<value;
        }
};
class DoubleObject
{
    double value; //Value of the double object
    public:
        DoubleObject(double value) //contructor for initialising DoubleObject
        {
            this->value = value;
        }
        double operator ! () //DoubleObject to double
        {
            return value;
        }
        IntObject operator ~ () //DoubleObject to IntObject
        {
            IntObject iobj((int)value);
            return iobj;
        }
        void display() //display the DoubleObject
        {
            cout<<value;
        }
};

int main()
{
    IntObject i(5); //IntObject with value 5
    DoubleObject d(7.6); //DoubleObject with value 7.6
    int integerResult = !i; //IntObject to int
    double doubleResult = !d; //DoubleObject to double
    cout<<"\nInteger of IntObject: "<<integerResult<<endl;
    cout<<"\nDouble of DoubleObject: "<<doubleResult<<endl;
    IntObject result = ~d; //DoubleObject to IntObject
    cout<<"\nIntObject of DoubleObject: ";
    result.display();
    cout<<endl;
    return 0;
}