//Problem 4 (ii)
//Pratyay Sarkar

#include <iostream>
using namespace std;

void f(int val, int &ref)
{
    val = val * 2; //the first paramter is modified (not refected in main)
    ref = ref - 5; //the second paramter is modified (refected in main)
    val = ref + 20; //the first paramter is modified again (not refected in main)
    cout << "f(): val = " << val << ", ref = " << ref << endl;
}

int main()
{
    int i = 10;
    int j = 10;
    f(i, j); //i is passed by by value,, and j's reference is passed
    //as a result, when i is printed, it retains its original value, 
    //while j has been modified by the f() fucntion 
    cout << "main(): i = " << i << ", j = " << j << endl;
    f(i, i); //as both variables are same, although the first is passed by value,
    //the second parameter gets the reference, and is able to modify the i variable
    cout << "main(): i = " << i << ", j = " << j << endl;
    return 0;
}