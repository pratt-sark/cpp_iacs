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

//to find the odd occurring element
int findOdd(int arr[], int n)
{
	int res = 0, i;
	for (i = 0; i < n; i++)
		res ^= arr[i];
	return res;
}

// Driver Method
int main(void)
{
	int n;
    cout<<"\nEnter size of array A: ";
    cin>>n;
    int a[n]; //creating an array of size n
    cout<<"\nEnter elements of array A: "<<endl;
    input(a,n);
    cout<<"\nArray A ->\t";
    display(a,n);
	cout << "The odd occurring element = "<< findOdd(a, n);
	return 0;
}