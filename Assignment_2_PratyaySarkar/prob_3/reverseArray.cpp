//Problem 3(ii)
//Pratyay Sarkar

#include <iostream>
using namespace std;

//take input in an array
void input(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
}

//display an array
void display(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;
}

//reverse the order of elements of array 'a'
void reverseArray(int a[], int n)
{
    int i,temp;
    cout<<"Reversing order of elements...Done.\n";
    for(i=0;i<n/2;i++)
    {
        temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }    
}

int main()
{
    int n;
    cout<<"\nEnter size of array A: ";
    cin>>n;
    int a[n]; //creating an array of size n
    cout<<"\nEnter elements of array A: "<<endl;
    input(a,n);
    cout<<"\nArray A ->\t";
    display(a,n);

    reverseArray(a,n); //reverse the order of elements of array 'a'
    cout<<"\nAfter reversing order of elements:\nArray A ->\t";
    display(a,n);
    return 0;
}