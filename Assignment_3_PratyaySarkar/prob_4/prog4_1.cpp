//Problem 4 (i)
//Pratyay Sarkar

#include <iostream>
using namespace std;

void f(int n) //for f(2) call, n=2 and for f(3) call, n=3
{
    while (n--) //n decremented to 1 for f(2) call, and to 2 and for f(3) call
    {
        static int flag = 0; //flag once intialized to 0, 
        //wont be re-intialized and will live till program ends
        int x = 0; //x will be declared and initializedin each iteration of the for loop
        //flag's value keeps increasing irrespective of its redeclaration in each iteration
        //or change in the function call entirely (for new calls, flag retains its value)
        cout << "f(): n = " << n << ", flag = " << flag++ << ", x = " << x++ << endl;
    }
    //the above loop keeps running until n=0, and the valie of x is always printed 0
    //as it's non-static and redeclared every iteration and initialized with 0
}

int main() 
{
    f(2);
    f(3);
    return 0;
}