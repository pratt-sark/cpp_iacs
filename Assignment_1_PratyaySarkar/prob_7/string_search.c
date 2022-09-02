//Program : 7
//Pratyay Sarkar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//checks if s2 is a substring of s1 or not
//If so, returns the index fo first occurence of s2 in s1
//Else, returns -1
int mySubStr(char* s1, char* s2, int len_s1, int len_s2)
{
    //declare a character array of length len_s1+1
    char *temp = (char*)(calloc(len_s1+1,sizeof(char)));
    for (int i=0;i<len_s1;i++) //iterate over the length of s1
    {
        strncpy(temp,s1+i,len_s2); //store a substring s1(0,len_s2-1) in temp
        if (strcmp(temp,s2)==0) //if it matches s2
            return i; //return index i
    }
    return -1; //return -1 by default
}

void main()
{
    int m,n;
    printf("\nEnter the length of the string 1: ");
    scanf("%d", &m);
    char *a = (char *)(calloc(m+1, sizeof(char)));
    printf("\nEnter string 1: \n");
    scanf("%s", a);

    printf("\n\nEnter the length of the string 2: ");
    scanf("%d", &n);
    char *b = (char *)(calloc(n+1, sizeof(char)));
    printf("\nEnter string 2: \n");
    scanf("%s", b);

    printf("\nString 1 = %s\n", a);
    printf("\nString 2 = %s\n", b);

    if (m<n) //if s2 is longer than s1
    {
        printf("\nSubstring to be searched for is longer than main string.\n");
        exit(1);
    }

    else
    {
        int val = mySubStr(a, b, m, n); //store the return value of mySubStr in val
        if(val>=0) //this means that s2 occurs in s1 first at index 'val
            printf("\nString 2 occurs first in String 1 in position = %d\n", val);
        else //this means that s2 does not occur in s1 at all
            printf("\nString 2 does not occur in String 1 at all.\n");
    }
}

/** --------------DOCUMENTATION EXCERPT FOR strncpy() function--------------------
 *  Declaration for strncpy() function.
        char *strncpy(char *dest, const char *src, size_t n);
    Parameters
        dest − Pointer to the destination array where the content is to be copied.
        src − Pointer to the string to be copied.
        n − The number of characters to be copied from source.
    ------------------------------------------------------------------------------
 */