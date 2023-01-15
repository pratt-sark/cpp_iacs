#include <iostream>
#include <vector>
using namespace std;

class Sentence
{
    string s; // the sentence
    public:
    Sentence(string s)
    {
        this->s = s;
    }
    void print()
    {
        cout << s;
    }
    void changeCase(string toCase)
    {
        int i; string temp="";
        for(i=0;i<s.length();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                if(toCase == "L" || toCase == "l")
                    s[i] = (char)(s[i]+32);
            }
            else if(s[i]>='a' && s[i]<='z')
            {
                if(toCase == "U" || toCase == "u")
                    s[i] = (char)(s[i]-32);
            }
        }
    }
};

class Paragraph
{
    vector <Sentence> p; // the paragraph
    public:
    Paragraph(vector <Sentence> p)
    {
        this->p = p;
    }
    void print()
    {
        cout << "The paragraph : "<< endl;
        int i;
        for (i = 0; i < p.size(); i++)
        {
            p[i].print();
            cout<<endl;
        }
    }
    void changeCase(string toCase)
    {
        int i;
        for (i = 0; i < p.size(); i++)
            p[i].changeCase(toCase);
    }
    void addSentence(string t)
    {
        p.push_back(t);
    }
};

int main()
{
    vector<Sentence> v;
    Paragraph p(v);
    int c; string x;
    while(true)
    {
        cout << "\nEnter 0 to terminate\n1 to add a sentence\n2 to display paragraph\n3 to change case\n\n";
        cin>>c;
        switch(c)
        {
            case 0: exit(0); break;
            case 1: cout<<"\nEnter the sentence you want to add\n"; 
                    getline(cin>>ws,x); p.addSentence(x); p.print(); break;
            case 2: p.print(); break;
            case 3: cout<<"Enter U for Upper Case and L for Lower Case\n";
                    cin>>x;
                    p.changeCase(x);
                    cout<<"\nAfter changing case, the paragraph:\n"; 
                    p.print(); break;
            default: cout<<"\nWrong Choice\n";
        }
    }
}