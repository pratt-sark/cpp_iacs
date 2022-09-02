//Program : 9 (ii)
//Pratyay Sarkar

#include <stdio.h>

//swap two integers using a third variable
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main()
{
    int a,b; //the two integers that are to be swapped
    printf("\nEnter the first number (a): ");
    scanf("%d", &a);
    printf("\nEnter the second number (b): ");
    scanf("%d", &b);

    printf("\n------------------------------------------------\n");
    printf("\nBefore swapping, a = %d, b = %d\n", a, b);
    swap(&a,&b);
    printf("\nAfter swapping, a = %d, b = %d\n", a, b);
    printf("\n------------------------------------------------\n");
}