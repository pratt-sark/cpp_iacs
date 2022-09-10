//Program : 2
//Pratyay Sarkar

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<math.h>

void input(int n[],int s);
void display(int *arr,int n);
int max(int a, int b);
int *add(int n1[],int n2[],int s1,int s2);
int *mult(int n1[],int n2[],int s1,int s2);

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
   
   printf("\n\nResultant number after addition = ");
   display(out,max(s1,s2)+1);

   //call the mult function to get the result of addition of n1 and n2
   out = mult(n1,n2,s1,s2);
   printf("\nResultant number after multiplication = ");
   display(out,s1+s2+s2);
   printf("\n----------------------------------------------------------------\n\n");
}

//returns the maximum of two integers
int max(int a, int b)
{
	return (a>b)?a:b;
}

//accepts the elements of an integer array
void input(int n[],int s)
{
   int i;
   for(i = 0; i < s; i++)
      scanf("%d",&n[i]);
}

//displays an array of integers
void display(int *arr,int n)
{
	int i;
   bool onlyLeadingZeroesTillNow = true;
	for (i=0;i<n;i++)
   {
      if(onlyLeadingZeroesTillNow && arr[i]==0)
         continue;
      printf("%d",arr[i]);
      onlyLeadingZeroesTillNow = false;
   }
}

//adds two large numbers represnted as integer arrays
int *add(int n1[],int n2[],int s1,int s2)
{
   // printf("\nadd received these numbers ->"); display(n1,s1); 
   // printf("\n"); display(n2,s2); printf("\n");
   int i,j,len,carry=0,t=0,*out,k;

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

   for(i=len-1,k=len;i>=0;i--,k--)
   {
      //if the number with less digits (n2) still has digits left to be added
   	if(j>=0) 
   	{
   	   t=n1[i]+n2[j]+carry; //store the sum of the i-th digit of n1, j-th digit of n2 and carry
      	out[k] = t%10; //determine the i-th digit of the output number
      	carry = t/10;	//determine the carry generated from last addition
      	j--; //decrement index of the current digit of n2
   	}
   	else //if the number with less digits (n2) has no more digits left to be added
   	{	
         t=n1[i]+carry; //store the sum of the i-th digit of n1 and carry
         out[k] = t; //determine the i-th digit of the output number
         carry = 0; //single digit addition, therefore no carry
      }      
   }
   if(k>=0) //add remaining carry to current index of out, if any
      out[k]=carry;
   return out; //return the output number
} 

//multiplies two large numbers represented as integer arrays
int *mult(int n1[],int n2[],int s1,int s2)
{
   int num_of_zeroes = 0; //number of trailing zeroes in each iteration
   int i,j,*out,*tempOut; //i,j are itertors, out and tempOut are explained later
   int k,t=0; //k - index of tempOut, t = temporary var 
   int carry=0,len=s1+s2;//len - length of output number, carry holds carry in each iteration
   out = (int *)calloc(len,sizeof(int)); //output number of size s1+s2

   //Always making sure that n1 has more digits than n2, or equal digits
   if(s1<s2) 
   {
      //swapping done using temporary variables
      int numTemp = s1;
      s1 = s2;
      s2 = numTemp;
      int *temp = n1; 
      n1 = n2;
      n2 = temp; 
   }

   for(i=s2-1;i>=0;i--)
   {
      //declare a temporary array for storing product of n2[i] and n1
      tempOut = (int *)calloc(s1+1+num_of_zeroes,sizeof(int));  
      for(j=s1-1,k=s1,carry=0;j>=0;j--,k--) //multiply n2[i] with the entirety of n1
      {
         t = n2[i]*n1[j] + carry;
         tempOut[k] = t%10;
         carry = t/10; 
         // printf("\nt = %d, Carry = %d, tempout size = %d\n",t,carry,s1+1+num_of_zeroes);
         // printf("tempout = "); display(tempOut,s1+1+num_of_zeroes);
      }
      if(k>=0) //add remaining carry to current index of tempOut, if any
         tempOut[k] = carry;
      
      //add tempOut to output number, with num_of_zeroes number of trailing zeroes added to tempOut
      out = add(out,tempOut,len,s1+1+num_of_zeroes);
      len++; //my implementation of add(..) function increases the length of output string by one
      num_of_zeroes++; //increase the number of trailing zeroes
      free(tempOut); //free memory of tempOut
   }
   return out; // Eg: Check with these numbers --> 13246 and 9879
}