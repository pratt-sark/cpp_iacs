//Problem 1
//Pratyay Sarkar

#include <iostream>
#include <string>
using namespace std;

static unsigned int course_id_global_counter = 100;

//Structure to represent the course
struct Course
{
    unsigned int course_id; // unique identifier for the course
    unsigned short semester; // semester in which the course is offered
    unsigned int limit; // maximum number of students to accept the course
    const char* name; // name of the course
};

typedef struct Course Course;

//checks whether two courses are offered in the same semester or not
inline bool checkSameSem(Course &c1, Course &c2)
{
    return (c1.semester == c2.semester);
}

//checks if two courses are identical or not, not considering
//the course_id to be a valid differentiator
inline bool checkIdentical(Course &c1, Course &c2)
{
    return (c1.name == c2.name && c1.semester == c2.semester && c1.limit == c2.limit);
}

//Update the details of a Course:
//index - 1 for course_id updation, 2 for semester number updation, 3 for limit updation
void updateDetails (Course &c,unsigned short index)
{
    switch (index)
    {
        case 1: 
            cout<<"\nYou are updating the ID for Course "<<c.name<<"....\n"<<endl;
            cout<<"Please enter new ID for the course: ";
            cin>>c.course_id;
            break;
        case 2: 
            cout<<"\nYou are updating the semester in which the Course "<<c.name<<" is offered...."<<endl;
            cout<<"Please enter new semester for the course: ";
            cin>>c.semester;
            break;
        case 3: 
            cout<<"\nYou are updating the course limit (max number of enrolled students)....\n"<<endl;
            cout<<"Please enter new course limit: ";
            cin>>c.limit;
            break;
        default: cout<<"\nExiting update function due to invalid update request..\n\n"<<endl;
    }
}

//to accept course details from the user
void inputCourse(Course &c)
{
    cout<<"\n\n-------------Requesting Course "<<course_id_global_counter%100+1<<" Input---------------\n";
    char *s = new char[100]; //character buffer to accept name of the course, 
    //as course_id is const char* and cannot be directly modified
    c.course_id = course_id_global_counter++;
    cout<<"\nPlease enter course name: ";
    cin>>s; 
    c.name = s; 
    // cout<<"\ns ="<<s<<endl; //for debugging

    cout<<"\nPlease enter course limit (max number of students): ";
    cin>>c.limit; 
    cout<<"\nPlease enter course semester: ";
    cin>>c.semester;
    cout<<"\n------------Input Accepted Successfully------------\n";
}

//to display course details in the console
void displayCourse(const Course &c)
{
    cout<<"\n\n--------------Course Details---------------\n";
    cout<<"Course Name: "<<c.name<<endl;
    cout<<"Course ID: "<<c.course_id<<endl;
    cout<<"Semester offered in: "<<c.semester<<endl;
    cout<<"Limit of students: "<<c.limit<<endl;
    cout<<"---------------------------------------------";
}

int main()
{
    Course c1, c2; //create two courses
    inputCourse(c1); //take input for course 1
    inputCourse(c2); //take input for course 2
    displayCourse(c1); //display course 1
    displayCourse(c2); //display course 2
    
    if(checkSameSem(c1,c2)) //check for same semester
        cout<<"\nCourse1 and Course2 are offered in the SAME semester."<<endl;
    else
        cout<<"\nCourse1 and Course2 are offered in DIFFERENT semesters."<<endl;

    if(checkIdentical(c1,c2)) //check if the two courses are identical
        cout<<"\n\nCourse1 and Course2 are IDENTICAL."<<endl;
    else
        cout<<"\n\nCourse1 and Course2 are NOT IDENTICAL."<<endl;

    updateDetails(c1,1); //update course_id of course 1
    updateDetails(c2,2); //update semester of course 2

    displayCourse(c1); //display course 1 to see if the changes are reflected
    displayCourse(c2); //display course 2 to see if the changes are reflected
    
    return 0;
}