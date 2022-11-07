//Program : 3
//Pratyay Sarkar

#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(const char *str,int len)
{
    int i,j;
    char *s = new char[len-1]; 
    for(i=len-1,j=0;i>=0;i--,j++)
    {
        s[j]=str[i];
        // cout<<"\n"<<str[i];
    }
    if(strcmp(s,str) == 0)
        return true;
    else
    {
        cout<<"\nReversed Word = "<<s<<endl;
        return false;
    }
}

int main()
{
    int length;
    cout<<"\nEnter the length of the string: ";
    cin>>length;
    char *s = new char[length];
    cout<<"\nEnter the string: ";
    cin>>s;
    cout<<"\nOriginal Word: ";
    cout<<s;
    if(isPalindrome(s,length))
        cout<<"\nPALINDROME WORD!"<<endl;
    else
        cout<<"\nNOT Palindrome word.\n"<<endl;
}