#include <iostream>
using namespace std;
int main()
{
	unsigned int i = 1;
	char *c = (char*)&i;
	if (*c)
		cout<<"\nThis system follows LITTLE Endian format.\n";
	else
		cout<<"\nThis system follows BIG Endian format.\n";
	return 0;
}