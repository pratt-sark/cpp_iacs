#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;

class Command
{
    public :
    virtual void execute() = 0;
    virtual void log() = 0;
};
class DisplayFileCommand : public Command
{
    private:
    string filename;
    public:
    DisplayFileCommand(string filename)
    {
        this->filename = filename;
    }
    void execute()
    {
        ifstream file(filename);
        string line;
        while(getline(file,line))
            cout << line << endl;
        
        file.close();
        log();
    }
     
    void log()
    {
        ofstream file("log.txt",ios::app);
        file << "DisplayFileCommand: " << filename << endl;
        file.close();
    }
};


class ShowTimeCommand : public Command
{
    public:
    void execute()
    {
        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "The local date and time is: " << dt << endl;
        log();
    }
    void log()
    {
        ofstream file("log.txt",ios::app);
        time_t now = time(0);
        char* dt = ctime(&now);
        file << "ShowTimeCommand: " << dt << endl;
        file.close();
    }
};

class HelpCommand : public Command
{
    public :
    void execute()
    {
        cout << "DisplayFileCommand : Displays the content of the file" << endl;
        cout << "HelpCommand : Displays the list of commands" << endl;
        cout << "ShowTimeCommand : Displays the current time" << endl;
        log();
    }
    void log()
    {
        ofstream file("log.txt",ios::app);
        
        file << "HelpCommand: " << endl;
        file.close();
    } 
};

int main()
{
    Command *commands[3];
    commands[0] = new DisplayFileCommand("data_test.txt");
    commands[1] = new HelpCommand();
    commands[2] = new ShowTimeCommand();
    commands[0]->execute();
    commands[1]->execute();
    commands[2]->execute();
    return 0;
}

