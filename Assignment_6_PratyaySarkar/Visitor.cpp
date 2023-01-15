#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int roll;
    string name;
    int marks;
};

typedef struct Student Students;
template <typename T>
void Student_selection_sort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        T temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

bool operator<(Students a, Students b)
{
    return (a.marks < b.marks);
}

bool operator<(string a, string b)
{
    int x = a.compare(b);
    return (x < 0);
}

int main()
{
    int n;
    cout << "Enter the number of students: " << endl;
    cin >> n;
    Students *arr = new Students[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the roll number: " << i + 1 << endl;
        cin >> arr[i].roll;
        cout << "Enter the name: " << i + 1 << endl;
        cin >> arr[i].name;
        cout << "Enter the marks: " << i + 1 << endl;
        cin >> arr[i].marks;
    }

    Student_selection_sort<Students>(arr, n);
    cout << "Sorted list of students -->" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Roll number of student " << i + 1 << " is " << arr[i].roll << endl;
        cout << "Name of student " << i + 1 << " is " << arr[i].name << endl;
        cout << "Marks of student " << i + 1 << " is " << arr[i].marks << endl;
    }

    // Sort an array of integers
    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int *arr_int = new int[size];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size; i++)
        cin >> arr_int[i];

    Student_selection_sort<int>(arr_int, size);
    cout << "The sorted array is" << endl;
    for (int i = 0; i < size; i++)
        cout << arr_int[i] << " ";

    cout << endl;

    // Sort an array of characters
    int size_char;
    cout << "Enter the size of the array" << endl;
    cin >> size_char;
    char *arr_char = new char[size_char];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size_char; i++)
        cin >> arr_char[i];

    Student_selection_sort<char>(arr_char, size_char);
    cout << "The sorted array : " << endl;
    for (int i = 0; i < size_char; i++)
        cout << arr_char[i] << " ";

    cout << endl;
    // Sort an array of strings
    int size_string;
    cout << "Enter the size of the array" << endl;
    cin >> size_string;
    string *arr_string = new string[size_string];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size_string; i++)
        cin >> arr_string[i];
    
    Student_selection_sort<string>(arr_string, size_string);
    cout << "The sorted array is" << endl;
    for (int i = 0; i < size_string; i++)
        cout << arr_string[i] << " ";
    
    cout << endl;
}
