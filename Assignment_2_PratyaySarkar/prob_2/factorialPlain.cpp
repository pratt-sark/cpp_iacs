//Problem 2(i)
//Pratyay Sarkar

#include <iostream>
using namespace std;

int fact(int n)
{
    //error checking for negative number inputs
    if(n<0) throw std::invalid_argument("\nFactorial cannot be calculated for negative numbers. Retry.\n");
    if(n==0) return 1; //base case
    else return n*fact(n-1); //recursion happens here
}

int main()
{
    int n;
    cout<<"\nEnter a positive integer: ";
    cin>>n;

    int factorial = fact(n); //correctly works upto n=12
    cout<<"\nFactorial = "<<factorial<<endl;

    return 0;
}