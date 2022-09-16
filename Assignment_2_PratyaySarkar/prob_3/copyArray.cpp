//Problem 3(i)
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

//copy elements of array 'a' into array 'b'
void copyArray(int a[], int b[], int n)
{
    int i;
    cout<<"Copying elements...Done.\n";
    for(i=0;i<n;i++)
        b[i] = a[i];
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

    int b[n]; //creating another array of same size
    cout<<"\nCreating a new array B.....\n";
    copyArray(a,b,n); //copying all elements of array A to array B
    cout<<"\nArray B ->\t";
    display(b,n); 
    return 0;
}