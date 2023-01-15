#include <iostream>
#include <vector>
using namespace std;

class Overflow : public exception
{
public:
    void message()
    {
        cout << "\nStack Overflow Exception\n";
    }
};

class Underflow : public exception
{
public:
    void message()
    {
        cout << "\nStack Underflow Exception\n";
    }
};

class Stack
{
    vector<int> stack;
    const int max = 10;

public:
    void push(int x)
    {
        if (stack.size() == max)
            throw new Overflow();
        stack.push_back(x);
    }
    int pop()
    {
        if (stack.size() == 0)
            throw new Underflow;
        int x = stack.back();
        stack.pop_back();
        return x;
    }
    void display()
    {
        int i;
        for (i = stack.size() - 1; i >= 0; i--)
            cout << stack[i] << endl;
    }
};

int main()
{
    Stack s;
    int c, x;
    try
    {
        while (true)
        {
            cout << "\nEnter 0 to exit\n1 to push an element\n2 to pop an element\n3 to display stack\n";
            cin>>c;
            switch (c)
            {
            case 0:
                exit(0);
                break;
            case 1:
                cout << "\nEnter an element: ";
                cin >> x;
                s.push(x);
                break;
            case 2:
                cout << "\nThe popped element is " << s.pop() << endl;
                break;
            case 3:
                cout << "The stack --> \n";
                s.display();
                break;
            default:
                cout << "\nWrong choice.\n";
                exit(0);
            }
        }
    }
    catch (Overflow e)
    {
        e.message();
    }
    catch (Underflow e)
    {
        e.message();
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }
}