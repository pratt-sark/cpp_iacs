//Problem 1 (iv)
//Pratyay Sarkar

#include <iostream>
using namespace std;

void f(double val, int val2)
{
    int x = val; //OK: truncated (int) value of val assigned to x
    int x2 {val}; //narrowing conversion of 'val' from 'double' to 'int' inside { }
    char c {val2}; //narrowing conversion of 'val2' from 'int' to 'char' inside { }
    char c2 {24}; //24 is in range 0-255, so accepted as a valid char intializer
    char c3 {264}; //narrowing conversion of '264' from 'int' to 'char' inside { }
    int x3 {2.0}; //narrowing conversion of '2.0' from 'double' to 'int' inside { }
    int x4 {}; //x4 declared here
    int x4[3] {}; //ERROR: redeclaration of variable x4
}

int main()
{
    double d=5.0;
    int i=2;
    f(d,i);
    return 0;
}