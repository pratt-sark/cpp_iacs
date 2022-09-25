//Problem 3 (iv)
//Pratyay Sarkar

void f(const float &a) {}
void g(float &b) {}
void h(double d, float r, int i)
{
    f(2.0f);
    f(r);
    f(2*r);
    f(d);
    f(i);

    g(2.0f); //initial value of reference to non-const must be an lvalue

    g(r);

    g(2*r); //initial value of reference to non-const must be an lvalue

    g(d); //a reference of type "float &" (not const-qualified)  
    //cannot be initialized with a value of type "double"

    g(i); //a reference of type "float &" (not const-qualified) 
    //cannot be initialized with a value of type "int"
}

int main()
{
    double x = 5.5;
    float y = 6.3f;
    int z = 21;
    h(x,y,z);
    return 0;
}