//Problem 1 (v)
//Pratyay Sarkar

#include <iostream>
using namespace std;

void f(char* p)
{
    char s[] = "Gorm";

    const char* pc = s; //the content to which the pointer points to is constant (unmodifiable)
    pc[3] = 'g'; //ERROR: assignment is not allowed in a location holding a constant character 
    pc = p;

    char *const cp = s; //the pointer is a constant pointer, cannot point to anything other than initial pointing location
    cp[3] = 'a';
    cp = p; //ERROR: constant pointer cannot be reassigned

    const char *const cpc = s; //both the pointer and contents of the memory are constants
    cpc[3] = 'a'; //ERROR: assignment is not allowed in a location holding a constant character
    cpc = p; //ERROR: constant pointer cannot be reassigned

    const int a = 5;
    const int* pa1 = &a;
    int *pa2 = &a; //ERROR: invalid conversion from 'const int*' to 'int*'
}

int main()
{
    char a[] = "IACS";
    f(a);
    return 0;
}