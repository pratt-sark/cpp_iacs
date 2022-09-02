//Program : 2
//Pratyay Sarkar

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//returns the maximum of two integers
int max(int a, int b)
{
	return (a>b)?a:b;
}

//displays an array of integers
void display(int *arr,int n)
{
	int i;
	for (i=0;i<n-1;i++)
		printf("%d",arr[i]);
}

//adds two large numbers represnted as integer arrays
int *add(int n1[],int n2[],int s1,int s2)
{
   int i,j,len,carry=0,t=0,*out;

   //Always making sure that n1 has more digits than n2, or equal digits
   if(s1>=s2) //if n1 already satisfies that, fine
   {
      len = s1; //len holds the length of the number with more digits
      j=s2-1; //j holds the index of last digit of the number with less digits
   }
   else //here, n2 has more digits than n1, so for my algorithm to work, swap n1 and n2
   {
      len = s2; //len holds the length of the number with more digits
      j=s1-1; //j holds the index of last digit of the number with less digits

      //swapping done using a temporary variable
      int *temp = n1; 
      n1 = n2;
      n2 = temp; 
   }

   //the output array (holding the output number) has size = max(s1,s2)+1 
   out = (int *)calloc(len+1,sizeof(int)); 

   for(i=len-1;i>=0;i--)
   {
      //if the number with less digits (n2) still has digits left to be added
   	if(j>=0) 
   	{
   	   t=n1[i]+n2[j]+carry; //store the sum of the i-th digit of n1, j-th digit of n2 and carry
      	out[i] = t%10; //determine the i-th digit of the output number
      	carry = t/10;	//determine the carry generated from last addition
      	j--; //decrement index of the current digit of n2
   	}
   	else //if the number with less digits (n2) has no more digits left to be added
   	{	
         t=n1[i]+carry; //store the sum of the i-th digit of n1 and carry
         out[i] = t; //determine the i-th digit of the output number
         carry = 0; //single digit addition, therefore no carry
      }      
   } 
   return out; //return the output number
} 

//multiplies two large numbers represented as integer arrays
int *mult(int n1[],int n2[],int s1,int s2)
{

}

//accepts the elements of an integer array
void input(int n[],int s)
{
   int i;
   for(i = 0; i < n; i++)
      scanf("%d",&n[i]);
}

void main()
{
   int *n1,*n2,*out; //n1 - first number, n2 - second number, out - output number
   int s1,s2; //s1 - number of digits in first number, s2 - number of digits in second number
   
   printf("\n\nEnter the size of the n1: ");
   scanf("%d",&s1);
   n1 = (int *)calloc(s1,sizeof(int));
   
   printf("\nEnter the first number: ");
   input(n1,s1);

   printf("\nEnter the size of the n2: ");
   scanf("%d",&s2);
   n2 = (int *)calloc(s2,sizeof(int));
   
   printf("\nEnter the second number: ");
   input(n2,s2);

   printf("\nFirst Number = ");
   display(n1,s1);
   printf("\nSecond Number = ");
   display(n2,s2);
   
   //call the add function to get the result of addition of n1 and n2
   out = add(n1,n2,s1,s2);
   
   printf("\n\nResultant number after addition: = ");
   display(out,max(s1,s2)+1);

   //call the mult function to get the result of addition of n1 and n2
   out = mult(n1,n2,s1,s2);
   printf("\n\nResultant number after multiplication: = ");
   display(out,max(s1,s2)+1);
}