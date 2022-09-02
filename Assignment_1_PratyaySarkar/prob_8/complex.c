//Program : 8
//Pratyay Sarkar

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Structure representing a Complex number
struct complex
{
    double x; //real part
    double y; //complex part
};

typedef struct complex Complex; //naming an alias for struct complex

//add two complex numbers
Complex add (Complex A, Complex B)
{
    Complex C; //the resultant Complex number
    C.x = A.x + B.x; //add the real parts, this forms real part of the result
    C.y = A.y + B.y; //add the complex parts, this forms complex part of the result
    return C;
}

//multiply two complex numbers
Complex mult (Complex A, Complex B)
{
    Complex C; //the resultant Complex number

    //real part of the result, the x parts are already real, and
    C.x = A.x*B.x - A.y*B.y; //multiplying two complex parts gives the minus sign
    //complex part, multiplying real parts with complex parts
    C.y = A.y*B.x + B.y*A.x; // gives the complex part of the resultant complex number

    return C; //return the resultant complex number
}

//Display a Complex number in proper format
void display(Complex A)
{
    printf("%lf", A.x); //print the real part of the complex number
    if(A.y==0) //if there's no complex part, dont do anything and return
        return;
    else if(A.y<0) //if the complex part is negative, print a minus sign
        printf(" -");
    else //if the complex part is positive, print a plus sign
        printf(" +");
    printf(" %lfi", fabs(A.y)); //now print the absolute value of the complex part
}

void main()
{
    Complex A,B,sum,product;
    printf("\n\nEnter the Complex number A: ");
    printf("\nReal Part = ");
    scanf("%lf", &A.x);
    printf("Complex Part = ");
    scanf("%lf", &A.y);

    printf("\n\nEnter the Complex number B: ");
    printf("\nReal Part = ");
    scanf("%lf", &B.x);
    printf("Complex Part = ");
    scanf("%lf", &B.y);

    printf("\n-------------------------------------------------------------\n");
    printf("\nThe Complex Number (A) = ");
    display(A);
    printf("\nThe Complex Number (B) = ");
    display(B);

    printf("\n\n-------------------------------------------------------------\n");
    printf("\nThe Complex Number (A+B) [Sum] = ");
    sum = add(A, B); //call the sum function
    display(sum); 

    printf("\nThe Complex Number (A*B) [Product] = ");
    product = mult(A, B); //call the product function
    display(product); 
    printf("\n\n-------------------------------------------------------------\n");
}