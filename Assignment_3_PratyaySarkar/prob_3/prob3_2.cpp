//Problem 3 (ii)
//Pratyay Sarkar

#include <iostream>
using namespace std;

void f(int i) 
{
    int x = i*2;
    switch (i) 
    {
        case 3: cout<<"Three"<<endl;
        break;
        case 3.2: cout<<"Slightly exceeds three"<<endl; // double not allowed as label value
        break;
        case 6-4: cout<<"Less than three"<<endl;
        break;
        case 6-3: cout<<"Again three"<<endl; //same label value as first case (case 3)
        break;
        case x: cout<<"What’s this?"<<endl; //label expression must be a constant value
        break;
    }
}

int main() 
{
    f(3);
    return 0;
}