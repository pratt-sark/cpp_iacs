//Program : 2
//Pratyay Sarkar

#include <iostream>
using namespace std;

class IntContainer
{
    int n; //size of container
    int *elements; //array of elements
    public:
        IntContainer(int n) //allocate memory for container
        {
            elements = new int[n];
            this->n = n; //intialize size of container
        }
        void input() //to take input to container
        {
            int i;
            for (i = 0; i < n; i++)
                cin>>elements[i];
        }
        void display() //to display container
        {
            int i;
            for (i = 0; i < n; i++)
                cout<<elements[i]<<"\t";
            cout<<endl;
        }
        void operator++ () //prefix increment
        {
            int i;
            for (i = 0; i < n; i++)
                elements[i]=elements[i]+1;
        }
        void operator-- () //prefix decrement
        {
            int i;
            for (i = 0; i < n; i++)
                elements[i]=elements[i]-1;
        }
        void operator++ (int) //postfix increment (int parameter receives default value 0)
        {
            int i;
            for (i = 0; i < n; i++)
                elements[i]=elements[i]+1;
        }
        void operator-- (int) //postfix decrement (int parameter receives default value 0)
        {
            int i;
            for (i = 0; i < n; i++)
                elements[i]=elements[i]-1;
        }
        void operator+= (int val) //increment and assignment operator overloading
        {
            int i;
            for (i = 0; i < n; i++)
                elements[i]=elements[i]+val;
        }
        void operator-= (int val) //decrement and assignment operator overloading
        {
            int i;
            for (i = 0; i < n; i++)
                elements[i]=elements[i]-val;
        }
};

int main()
{
    int n; //size of container
    cout<<"\nEnter size of container: ";
    cin>>n;
    IntContainer ic(n); //IntContainer of size n
    cout<<"\nEnter elements of container: "<<endl;
    ic.input();
    cout<<"\nThe Container initially: "<<endl;
    ic.display();
    ic++; //postfix increment
    cout<<"\nThe Container after increment ++: "<<endl;
    ic.display();
    ic--; //postfix decrement
    cout<<"\nThe Container after decrement --: "<<endl;
    ic.display();
    ic+=20; //increment by 20 and then assignment
    cout<<"\nThe Container after increment +=20: "<<endl;
    ic.display();
    ic-=10; //decrement by 10 and then assignment
    cout<<"\nThe Container after decrement -=10: "<<endl;
    ic.display();
    return 0;
}