#include <iostream>
void f(int) { std::cout<<"f1"<<std::endl;}
void f(int = 0){std::cout<<"f(int = 0)"<<std::endl;}    //redefinition of ‘void f(int)’
int main(){
    f(5);
    f(0);
    f();    //too few arguments to function ‘void f(int)’
    return 0;
}