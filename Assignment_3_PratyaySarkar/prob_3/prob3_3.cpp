//Problem 3 (iii)
//Pratyay Sarkar

int x1 = 7;
int square(int x) { return x*x;}

constexpr int x2 = 7;

// expression must have a constant value
// the value of variable "x1" (declared at line 1) cannot be used as a constant
constexpr int x3 = x1; 
constexpr int x4 = x2;

void f() 
{
    // expression must have a constant value
    // the value of variable "x1" (declared at line 1) cannot be used as a constant
    constexpr int y1 = x1;

    constexpr int y2 = x2;

    // cannot call non-constexpr function "square" (declared at line 2)
    // the return value of function "square" cannot be used as a constant
    constexpr int y3 = square(x1);

    // cannot call non-constexpr function "square" (declared at line 2)
    // the return value of function "square" cannot be used as a constant
    constexpr int y4 = square(x2);
}