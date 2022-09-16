//Problem 2(ii)
//Pratyay Sarkar

#include <iostream>
using namespace std;

int factQuick(int n) //to calculate factorial quickly without multiplications
{
    //error checking for numbers less than 0 or greater than 8
    if(n<0 || n>8) throw std::invalid_argument("\nNumber should be >=0 and <=8. Retry.\n");
    int fact[]={1,1,2,6,24,120,720,5040,40320}; //an array in which n-th index holds factorial(n)
    return fact[n]; //return factorial
}

int main()
{
    int n;
    cout<<"\nEnter a positive integer between 0 and 8 (both included): ";
    cin>>n;

    int factorial = factQuick(n);
    cout<<"\nFactorial = "<<factorial<<endl;

    return 0;
}