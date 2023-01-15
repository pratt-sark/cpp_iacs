#include <iostream>
using namespace std;

class AI
{
    public:
    bool usesKG;
};

class Neural : public AI
{
    public:
    void train(){}
};

class Symbolic : public AI
{
    public:
    void reason()
    {
        cout << "\nThis is reason." << endl;
    }
};

class NeuroSymbolic : public Neural, public Symbolic
{
    int placeholder;
};

int main()
{
    NeuroSymbolic* ai_ns = new NeuroSymbolic();
    ai_ns->reason(); 
    AI* ai = ai_ns; //base class "AI" is ambiguous
    bool b = ai_ns->usesKG; //"NeuroSymbolic::usesKG" is ambiguous
}