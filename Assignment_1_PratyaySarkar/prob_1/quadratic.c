//Program : 1
//Pratyay Sarkar

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define PRECISION pow(10,-10)

struct QuadraticEquation
{
    double a; //coeffecient of x^2 in ax^2 +bx +c = 0
    double b; //coeffecient of x in ax^2 +bx +c = 0
    double c; //constant value in ax^2 +bx +c = 0
    
    double x1; //root 1 in ax^2 +bx +c = 0
    double x2; //root 2 in ax^2 +bx +c = 0 

    bool hasRealRoots; //true if real roots exist, else false (false, unless specified)
    bool isEquation; //true if equation is at all an equation, else false (false, unless specified)
};

typedef struct QuadraticEquation qe;

qe findRoot(qe eqn);

int main()
{
    qe eqn;
    printf("\n================================\n");
    printf("\nEnter the quadratic equation:");
    printf("\na (coeffecient of x^2) = ");
    scanf("%lf", &eqn.a);
    printf("\nb (coeffecient of x) = ");
    scanf("%lf", &eqn.b);
    printf("\nc (constant value) = ");
    scanf("%lf", &eqn.c); 

    eqn = findRoot(eqn);

    if(!eqn.isEquation)
        printf("\nNot a valid equation.\n");
    else
    {
        if(!eqn.hasRealRoots)
            printf("\nEquation has complex roots.\n");
        else
            printf("\nRoots are: x1 = %lf, x2 = %lf\n", eqn.x1, eqn.x2);
    }
    return 0;
}

//solves a quadratic equation
qe findRoot(qe eqn)
{
    eqn.isEquation = true; //initially assume inputs form a valid equation

    if(eqn.a==0 && eqn.b==0) //no terms involving x appear, not an equation
        eqn.isEquation = false; //refute the intiial assumption

    else if (eqn.a==0) //the equation is not quadratic, but linear
    {
        eqn.x1 = eqn.x2 = -eqn.c/eqn.b; //equal roots calculated
        eqn.hasRealRoots = true; //equation has real roots
    }

    else
    {
        double D = eqn.b*eqn.b - 4*eqn.a*eqn.c; //discriminant calculated
        printf("\nD=%lf\n", D); //for debugging
        if(D>0)
        {
            eqn.x1 = (-eqn.b + sqrt(D))/(2*eqn.a); //root 1 calculated
            eqn.x2 = (-eqn.b - sqrt(D))/(2*eqn.a); //root 2 calculated
            eqn.hasRealRoots = true; //equation has real roots
        }
        else if (D<PRECISION && D>=0)
        {
            eqn.x1 = eqn.x2 = -eqn.b/(2*eqn.a); //equal roots calculated
            eqn.hasRealRoots = true; //equation has real roots
        }
        else
        {
            eqn.hasRealRoots = false; //equation has complex roots
            //to be improved later: complex roots finding
        }
    }
    return eqn;
}