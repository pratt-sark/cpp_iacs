//Program : 1
//Pratyay Sarkar

#include <iostream>
#include <string>
using namespace std;

//Class representing a date
class Date
{
    int day; // day of the month
    int month; // month of the year
    int year; // year
    mutable string dateFormat; //string format of the date

    public:
    void setStringDate(int,int,int);
    void setDate(int,int,int);
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    int getDay();
    int getMonth();
    int getYear();
    string getDate();
    bool checkLeap();
    void addYears(int);
    Date() // default constructor with some default values
    {
        day = 14;
        month = 10;
        year = 1985;
        dateFormat = "";
    }
    Date(int day, int month, int year) //parameterized constructor
    {
        setDate(day, month, year); //uses setter to set the date
    }
    Date(Date& date)
    {
        this->dateFormat = date.dateFormat;
        this->day = date.day;
        this->month = date.month;
        this->year = date.year;
    }
};

void Date :: setDay(int day) //set the day of Date object to 'day'
{
    setDate(day,this->month,this->year);
}

void Date :: setMonth(int month) //set the month of Date object to 'month'
{
    setDate(this->day,month,this->year);
}

void Date :: setYear(int year) //set the year of Date object to 'year'
{
    setDate(this->day,this->month,year);
}

int Date :: getDay() //get the day of the Date object
{
    return this->day;
}

int Date :: getMonth() //get the month of the Date object
{
    return this->month;
}

int Date :: getYear() //get the year of the Date object
{
    return this->year;
}

string Date :: getDate() //get the string representation of the Date object
{
    if(this->dateFormat == "")
        setStringDate(this->day, this->month, this->year);
    else 
        return this->dateFormat;
}

//set the date with passed values
void Date :: setDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
    setStringDate(day, month, year);
}

// generating the string representation of the date
// (additionally, checks for errors in inputs)
void Date :: setStringDate(int day, int month, int year)
{
    string s = " "+to_string(day)+", "+to_string(year); //Eg: s = "14, 1985"
    bool flag = false;
    switch (month) //choose month according to month
    {
        case 1: s = "January"+s; flag=(day>0 && day<=31); break;
        case 2: s = "February"+s; flag=((day>0 && day<=28)||(day==29 && checkLeap())); break;
        case 3: s = "March"+s; flag=(day>0 && day<=31); break;
        case 4: s = "April"+s; flag=(day>0 && day<=30); break;
        case 5: s = "May"+s; flag=(day>0 && day<=31); break;
        case 6: s = "June"+s; flag=(day>0 && day<=30); break;
        case 7: s = "July"+s; flag=(day>0 && day<=31); break;
        case 8: s = "August"+s; flag=(day>0 && day<=31); break;
        case 9: s = "September"+s; flag=(day>0 && day<=30); break;
        case 10: s = "October"+s; flag=(day>0 && day<=31); break;
        case 11: s = "November"+s; flag=(day>0 && day<=30); break;
        case 12: s = "December"+s; flag=(day>0 && day<=31); break;
        default: 
                s = "INVALID DATE"; 
                throw invalid_argument("Invalid month.");
                exit(1);
    }
    if(!flag || year<0)
    {
        throw domain_error("Invalid date.");
        exit(1);
    }
    this->dateFormat = s; //Eg: now the date will look like "October 14, 1985"
}

bool Date :: checkLeap()
{
    // cout<<"\nChecking for leap year..."<<endl;
    if(this->year % 400 == 0) //century year AND divisible by 400
        return true; // leap year
    else if(this->year % 100 == 0) //century year but NOT divisible by 400
        return false; //NOT leap year
    else return (this->year % 4 == 0); //Non-century years
    // if divisible by 4 : leap year, otherwise NOT
}

//add certain number of years to the current date
void Date :: addYears(int years)
{
    cout<<"\nAdding "<<years<<" year(s) to current date..."<<endl;
    // setDate(this->day, this->month, this->year + years);
    Date currentDate (this->day, this->month, this->year);
    int countLeapYears = 0;
    bool isCurrentLeapYear = checkLeap();
    for (int i=0; i<years; i++)
    {
        isCurrentLeapYear = currentDate.checkLeap();
        if(isCurrentLeapYear)
        {
            countLeapYears++;
            i+=4;
        }
        currentDate.setYear(this->year+1);
    }
    if(currentDate.getMonth()==2 && currentDate.getDay()>=29)
        countLeapYears--;

    int day,month,year;
    bool inFeb = this->month==2;
    day = this->day + countLeapYears;
    bool in31 = (this->month==1 || this->month==3 || this->month==5 || this->month==7 ||  this->month==8 || this->month==10 || this->month==12);
    if(!in31 && day%31>0)
    {
        this->day = day%31;
        this->month = this->month + 1;
    }
    else if(inFeb)
    {
        int div = 28 + (this->checkLeap())?1:0;
        if(day%div>0)
        {
            this->day = day%div;
            this->month = this->month + 1;
        }
    }
    else if (day%30>0)
    {
        this->day = day%30;
        this->month = this->month + 1; 
    }
    if(this->month%12>0)
    {
        this->month = this->month%12;
        this->year = this->year + 1;
    }
    this->year = this->year+years;
    setStringDate(this->day, this->month, this->year);
}

int main()
{
    int x; //temporary interger variable
    Date date1; //will use setters for date1
    cout<<"Enter day = ";
    cin>>x; date1.setDay(x);
    cout<<"Enter month = ";
    cin>>x; date1.setMonth(x);
    cout<<"Enter year = ";
    cin>>x; date1.setYear(x);

    Date date2(15,3,2020); //will use parameterized constructor for date2

    //using getter to display the date
    cout<<"\nDate 1: "<<date1.getDate()<<endl; 
    cout<<"\nDate 2: "<<date2.getDate()<<endl;

    if(date1.checkLeap()) //checking date1 for leap year
        cout<<"\n"<<date1.getDate()<<" is a LEAP YEAR."<<endl;
    else
        cout<<"\n"<<date1.getDate()<<" is NOT a Leap Year."<<endl;

    date1.addYears(3); //adding a certain number of years to date2
    cout<<"\nDate 1 after adding years: "<<date1.getDate()<<endl; //displaying to see reflected changes in date
    return 0;
}