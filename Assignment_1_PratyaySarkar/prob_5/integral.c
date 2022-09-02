//Program : 5
//Pratyay Sarkar

#include <stdio.h>
#include <math.h>

//a function which returns some value
double f(double x)
{
    return x*x*x*x;
}

//calculates definite integral of f(x) from a to b, n being number of equal intervals
double calculateIntegral(int a, int b, double n)
{
    //intialize i to lower bound of integral, result to zero and step to (b-a)/n
    double i=a,result=0,step=(b-a)/n;

    //this loop calculates sum of all f(i)'s except the f(a) and f(b)
    while (i<b) //while i is less than upper bound of integral
    {
        i+=step; //increment i by step
        result += f(i); //add f(i) to result
    }

    //use the formula of trapezoidal rule to calculate final result
    result = (step/2)*(f(a) +f(b) + 2*result);
    return result; //return the  final result, i.e. the value of the integral
}

void main()
{
    int a,b,n;
    printf("\n\nEnter lower limit of integral = ");
    scanf("%d",&a);
    printf("\nEnter upper limit of integral = ");
    scanf("%d",&b);
    printf("\nEnter number of equal intervals (n) = ");
    scanf("%d",&n);
    printf("\n\nValue of integral of f(x) from %d to %d = %lf\n",a,b,calculateIntegral(a,b,n));
}