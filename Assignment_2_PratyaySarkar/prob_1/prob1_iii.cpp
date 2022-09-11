//Problem 1 (iii)
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
    }//scope ends, the character variable 'a' is lost here

    cout << a << '\n'; //a is considered to be the integer variable
    return 0;
}

//OUTPUT: -1