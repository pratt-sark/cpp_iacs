#include <iostream>
using namespace std;

class Icon
{
    public:
    string name;
    virtual Icon *clone() = 0;
    void display()
    {
        cout<<"\nIcon Name: "<<name<<endl;
    }
};

class MenuIcon : public Icon
{
    public:
    MenuIcon()
    {
        name = "Menu";
    }
    Icon *clone()
    {
        Icon *icon = new MenuIcon();
        icon->name = name;
        return icon;
    }
};

class SearchIcon : public Icon
{
    public:
    SearchIcon()
    {
        name = "Search";
    }
    Icon *clone()
    {
        Icon *icon = new SearchIcon();
        icon->name = name;
        return icon;
    }
};

class OpenIcon : public Icon
{
    public:
    OpenIcon()
    {
        name = "Open";
    }
    Icon *clone()
    {
        Icon *icon = new OpenIcon();
        icon->name = name;
        return icon;
    }
};

class CloseIcon : public Icon
{
    public:
    CloseIcon()
    {
        name = "Close";
    }
    Icon *clone()
    {
        Icon *icon = new CloseIcon();
        icon->name = name;
        return icon;
    }
};

class IconStore
{
    Icon* iconList[4];
    public:
    IconStore()
    {
        iconList[0] = new MenuIcon();
        iconList[1] = new SearchIcon();
        iconList[2] = new OpenIcon();
        iconList[3] = new CloseIcon();
    }
    Icon* getIcon(int i)
    {
        if(i>4 || i<1)
            throw std::invalid_argument("Invalid Icon Index");
        return iconList[i]->clone();
    }
};

int main()
{
    cout<<"\nEnter the icon number: ";
    int i;
    cin>>i;
    IconStore iconstore;
    Icon* icon = iconstore.getIcon(i-1);
    icon->display();
    return 0;
}