//Program : 0 (i)
//Pratyay Sarkar

#include <stdio.h>
int main()
{
    int a=1,b=2,c=3,d=4,res=0;
    
    //Output -> 4
    //Explanation -> 1+2-3+4 = 3-3+4 = 4
    res = a+b-c+d;
    printf("res = %d\n",res);

    //Output -> 0
    //Explanation -> 1*2/3 = 2/3 = 0 (integer division occurs)
    res = a*b/c;
    printf("res = %d\n",res);

    //Output -> 3
    //Explanation -> 1+1*2%3 = 1+2%3 = 1+2 = 3
    res = 1+a*b%c;
    printf("res = %d\n",res);

    //Output -> -2
    //Explanation -> 1+4%2-3 = 1+0-3 = 1-3 = -2
    res = a+d%b-c;
    printf("res = %d\n",res);

    //Output -> 4
    //Explanation -> 4+3/2-1 = 4+1-1 (integer division occurs) = 5-4 = 4
    res = b = d+c/b-a;
    printf("res = %d\n",res);

    return 0;
}