//Problem 2
//Pratyay Sarkar

#include <iostream>
using namespace std;

//to return square of an integer value
inline int sq(int x)
{
    return x*x;
}

int main()
{
    int i,n,sum=0;
    cout<<"\nEnter the value of N: "<<endl;
    cin>>n; //accept the value of n

    for(i=1;i<=n;i++)
        sum+=sq(i); //do the sum calculation
    
    cout<<"\nSum = "<<sum<<endl; //display the sum
    return 0;
}