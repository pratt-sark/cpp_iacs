//Program : 3
//Pratyay Sarkar

#include <stdio.h>

int factorial (int n);

void main()
{
    int n,r;
    printf("\n-------------------------\n");
    printf("\nEnter the value of 'n' :");
    scanf("%d", &n);
    printf("\nEnter the value of 'r' :");
    scanf("%d", &r);

    //display the value of nCr
    printf("\nnCr = %dC%d = %d\n",n,r,factorial(n)/(factorial(r)*factorial(n-r)));
}

//calculates factorial of a number recursively
int factorial (int n)
{
    if(n==0) //base case, 0! = 1
        return 1;
    else //multiply the number with the factorial of (number-1)
        return n*factorial(n-1);
}