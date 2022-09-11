//Problem 1 (v)
//Pratyay Sarkar

#include <iostream>
using namespace std;

void f()
{
    int var = 1;
    int& r {var};
    int x = r;
    r = 2;
    int& r2; //'r2' declared as reference but not initialized
    ++r;
    int *pp = &r;
    extern int& r3;
    int& ei = 99; //invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'
    const int& ei2 = 99;
}

int main()
{
    f();
    return 0;
}