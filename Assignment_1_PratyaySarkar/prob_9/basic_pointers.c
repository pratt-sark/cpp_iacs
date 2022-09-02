//Program : 9 (i)
//Pratyay Sarkar

#include <stdio.h>

int main()
{
    int x,y;
    int *ptr;

    x = 10;
    ptr = &x;
    y = *ptr;

    //x is the value of the variable, &x is its address
    printf("%d is stored in location %p\n",x, &x);
    //*&x is the value at the address &x, which is essentiallythe value of x
    printf ("%d is stored in location %p \n", *&x, &x);

    //*ptr is the value at pointer ptr, and ptr is the location (&x)
    printf ("%d is stored in location %p \n", *ptr, ptr); 
    //y=*ptr, so same as above, &*ptr is the address of *ptr, or x, so it is same as &x
    printf ("%d is stored in location %p \n", y, &*ptr); 
    //ptr - pointer, &ptr - location of ptr
    printf ("%p is stored in location %p \n", ptr, &ptr); 
    //y is value at ptr, &y is &x
    printf ("%d is stored in location %p \n", y, &y);
    *ptr = 25; //value of changes to 25
    printf ("\nNow x = %d\n", x);
    return 0;
}