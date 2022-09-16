//Problem 4
//Pratyay Sarkar

#include <iostream>
using namespace std;

unsigned int countHighBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) //while n is not zero
    {
        count += n & 1; //n&1 essentially gives 1 if the LSB is 1, else 0
        n >>= 1; //perform a right shift to get rid of the LSB
    }
    return count;
}

unsigned int countTrailingLowBits(unsigned int n)
{
    unsigned int count = 0;
    //stop when the LSB is high
    while ((n&1)!=1) //n&1 essentially gives 1 if the LSB is 1, else 0
    {
        n >>= 1; //perform a right shift to get rid of the LSB
        count++;
    }    
    return count;
}

unsigned int reverseBits(unsigned int num)
{
    unsigned int NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0;
    
    int i;
    for (i = 0; i < NO_OF_BITS; i++)
        if ((num & (1 << i)))
            reverse_num |= 1 << ((NO_OF_BITS - 1) - i);

    return reverse_num;
}

int main()
{
    unsigned int a,b;
    cout<<"\nEnter the values of a and b: ";
    cin>>a>>b;

    //x << y essentialy does x*pow(2,y)
    cout<<"\n"<<a<<" multiplied by 8 = "<<(a << 3)<<endl;

    //function to count high bits is defined above
    cout<<"Number of 1s in binary representation of "<<a<<" = "<<countHighBits(a)<<endl;

    //function to count trailing low bits is defined above
    cout<<"Number of trailing 0s in binary representation of "<<a<<" = "<<countTrailingLowBits(a)<<endl;
    
    cout<<a<<" OR "<<b<<" = "<<(a|b)<<endl;
    cout<<a<<" AND "<<b<<" = "<<(a&b)<<endl;
    cout<<a<<" XOR "<<b<<" = "<<(a^b)<<endl;

    cout<<"\n"<<a<<" after reversing order of bits = "<<reverseBits(a)<<endl;
    return 0;
}