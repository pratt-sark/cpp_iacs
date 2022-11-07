#include <iostream>

void f(char, short, double){ std::cout<<"f1"<<std::endl;}
void f(int, int, int){std::cout<<"f2"<<std::endl;}

void F(int x, int y){std::cout<<"F1"<<std::endl;}
void F(char x, double y){std::cout << "F2" << std::endl;}

void k(double, double){std::cout<<"k1"<<std::endl;}
void k(int, int){std::cout<<"k2"<<std::endl;}

int main(){
    f('a', (short)2, (short)3);
    f('a', 3, 2);
    F(2,3);
    F('a', 5, 4);   //error: too many arguments to function 'F'
    F('a', 5);
    F('a', 'b');
    F(2, 2.5);  //more than one instance of overloaded function "F" matches the argument list
    k(1.2, 2.1);
    k(1, 2);
    k(2.3 , 2); //more than one instance of overloaded function "k" matches the argument list
    k(long(0), bool(0));
    return 0;
}