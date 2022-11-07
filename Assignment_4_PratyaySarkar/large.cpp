#include <iostream>
using namespace std;

class LargeNumber
{
    int *num;
    int size;

public:
    void setSize(int size)
    {
        this->size = size;
    }
    int getSize()
    {
        return this->size;
    }
    LargeNumber()
    {
        this->size = 0;
        num = nullptr;
    }
    LargeNumber(int size)
    {
        this->size = size;
        num = new int[size];
    }
    void input()
    {
        char *c;
        scanf("%s", c); // input to char array to facilitate easier user input
        int i;
        for (i = 0; i < this->size; i++)
            this->num[i] = c[i] - '0'; // conversion of those characters to integers
    }
    void display()
    {
        int i;
        bool onlyLeadingZeroesTillNow = true;
        for (i = 0; i < this->size; i++)
        {
            if (onlyLeadingZeroesTillNow && this->num[i] == 0)
                continue;
            printf("%d", this->num[i]);
            onlyLeadingZeroesTillNow = false;
        }
    }
    void add(LargeNumber n1, LargeNumber n2)
    {
        // printf("\nadd received these numbers ->"); display(n1,s1);
        // printf("\n"); display(n2,s2); printf("\n");
        int i, j, len, carry = 0, t = 0, k;

        // Always making sure that n1 has more digits than n2, or equal digits
        if (n1.size >= n2.size) // if n1 already satisfies that, fine
        {
            len = n1.size;   // len holds the length of the number with more digits
            j = n2.size - 1; // j holds the index of last digit of the number with less digits
        }
        else // here, n2 has more digits than n1, so for my algorithm to work, swap n1 and n2
        {
            len = n2.size;   // len holds the length of the number with more digits
            j = n1.size - 1; // j holds the index of last digit of the number with less digits

            // swapping done using a temporary variable
            LargeNumber tmp = n1;
            n1 = n2;
            n2 = tmp;
        }

        for (i = len - 1, k = len; i >= 0; i--, k--)
        {
            // if the number with less digits (n2) still has digits left to be added
            if (j >= 0)
            {
                t = n1.num[i] + n2.num[j] + carry; // store the sum of the i-th digit of n1, j-th digit of n2 and carry
                this->num[k] = t % 10;           // determine the i-th digit of the output number
                carry = t / 10;            // determine the carry generated from last addition
                j--;                       // decrement index of the current digit of n2
            }
            else // if the number with less digits (n2) has no more digits left to be added
            {
                t = n1.num[i] + carry; // store the sum of the i-th digit of n1 and carry
                this->num[k] = t;        // determine the i-th digit of the output number
                carry = 0;         // single digit addition, therefore no carry
            }
        }
        if (k >= 0) // add remaining carry to current index of out, if any
            this->num[k] = carry;
    }
};

// returns the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int size;
    cout << "\n\nEnter the size of the n1: ";
    cin >> size;
    LargeNumber n1(size);

    printf("\nEnter the first number: ");
    n1.input();

    cout << "\n\nEnter the size of the n1: ";
    cin >> size;
    LargeNumber n2(size);

    printf("\nEnter the second number: ");
    n2.input();

    printf("\nFirst Number = ");
    n1.display();
    printf("\nSecond Number = ");
    n2.display();

    LargeNumber out(max(n1.getSize(), n2.getSize()) + 1);

    // call the add function to get the result of addition of n1 and n2
    out.add(n1, n2);

    printf("\n\nResultant number after addition = ");
    out.display();
    return 0;
}