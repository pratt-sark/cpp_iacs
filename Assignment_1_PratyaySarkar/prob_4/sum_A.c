//Program : 4
//Pratyay Sarkar

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//the max error to be tolerated is 10^(-5)
const double ERROR = 0.00001;

//calculates factorial of a number recursively
int factorial (int n)
{
    if(n==0) //base case, 0! = 1
        return 1;
    else //multiply the number with the factorial of (number-1)
        return n*factorial(n-1);
}

//calculates the sum of the given series
double seriesSum(double x)
{
    int i=0, power=1, sign=1; //power and sign intialised to 1
    double term=0.0, sum=0.0; //term and sum intitialised to 0.0
    do
    {
        //the currwnt term in series is calculated
        term = sign*pow(x, power)/factorial(power); 
        sum += term; //term is added to sum
        sign*=-1; //sign is changed
        power+=2; //power is incremented by 2
    }while(fabs(term)>ERROR); //terminate loop if the term is precise enough (<ERROR)

    //number of terms printed for clarity (optional)
    printf("\n--------------------------------\n");
    printf("\nNumber of terms = %d\n", power/2+1);
    printf("\n--------------------------------\n");
    return sum; //return the sum of the series
}

void main()
{
    double x; //parameter value in the series
    printf("\n--------------------------------\n");
    printf("\nEnter the value of 'x' :");
    scanf("%d", &x);
    printf("\nSum of Series = %lf\n",seriesSum(x));
}