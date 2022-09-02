//Program : 0 (ii)
//Pratyay Sarkar

#include <stdio.h>
int main()
{
    //notice that 'val' is initialized to 1, but 'ans' isn't initialized at all
    //so 'ans' has some garbage value right now
    int ans, val=4; 

    val = val+1; //variable 'val' is incremented by 1 (now val = 5, ans = garbage)
    printf("ans=%d, val=%d\n", ans, val); //ans=garbage, val=5

    val++; //'val' is incremented by 1 using postfix operator (now val = 6, ans = garbage)
    ++val; //'val' is incremented by 1 using prefix operator (now val = 7, ans = garbage)
    printf("ans=%d, val=%d\n", ans, val); //ans=garbage, val=7

    ans = 2*val++; //2*current_value_of_val(i.e. 7), then increment val by 1 (now val=8, ans=14)
    printf("ans=%d, val=%d\n", ans, val); //ans=14, val=8

    val--; //'val' is decremented by 1 using postfix operator (now val = 7, ans = 14)
    --val; //'val' is decremented by 1 using prefix operator (now val = 6, ans = 14)
    printf("ans=%d, val=%d\n", ans, val); //ans=14, val=6

    ans = --val*2; //'val' is decremented by 1 first, then multiplied by 2 (now val=5, ans=10)
    printf("ans=%d, val=%d\n", ans, val); //ans=10, val=6

    ans = val--/3; //current_value_of_val(i.e. 5) is divided by 3 first, then 'val' is decremented by 1
    printf("ans=%d, val=%d\n", ans, val); //ans=1, val=4

    return 0;
}