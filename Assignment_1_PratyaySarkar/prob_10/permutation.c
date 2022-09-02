//Program : 10
//Pratyay Sarkar

#include <stdio.h>
#include <stdlib.h>

static int count=0;

//swaps two characters using a third variable
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

//permutes the digits of a number represented as a character array
void permute(char* a, int left, int right)  
{  
    // Base case  
    if (left == right)  
    {
        printf("%s\n",a);
        count++; //number of permutations incrementedn by 1
    }     
    else
    {  
        // Permutations made  
        for (int i = left; i <= right; i++)  
        {  
            // Swapping done  
            swap(&a[left], &a[i]);  
  
            // Recursion called  
            permute(a, left+1, right);  
  
            // Backtrack  
            swap(&a[left], &a[i]);
        }  
    }  
}  

void main()
{
    int n; //length of the number
    printf("\nEnter the length of the number: ");
    scanf("%d", &n);
    char *a = (char *)(calloc(n+1, sizeof(char)));
    printf("\nEnter a number: \n");
    scanf("%s", a); 
    printf("\n-------------------------------\nThe possible permutations are: \n");
    permute(a, 0, n-1); //permute in the digits of the number
    printf("\n-------------------------------\nTotal permutations printed = %d\n",count);
}