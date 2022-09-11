//Problem 1 (ii)
//Pratyay Sarkar

#include <iostream>
using namespace std;

int main()
{
    int a; //variable named 'a' declared here
    a = -1; //variable assigned a value

    //new scope starts
    {
        char a = 'A'; //declaration of the variable 'a' local to this scope
        cout << a << '\n'; //a is considered to be the locally declared character variable
    }//scope ends
    return 0;
}

//OUTPUT: A