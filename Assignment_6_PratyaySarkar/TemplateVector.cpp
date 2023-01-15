#include <iostream>
using namespace std;

class Negative_Size : public std::exception
{
public:
  void message()
  {
    cout << "Negative size is not allowed." << endl;
  }
};
template <class T>

class Vector
{
private:
  T *elem;
  int size;

public:
  Vector(int s)
  {
    try
    {
      if (s < 0)
        throw Negative_Size();
      else
      {
        size = s;
        elem = new T[size];
        for (int i = 0; i < size; i++)
        {
          cout << "Enter the elements: \n";
          cin >> elem[i];
        }
      }
    }
    catch (Negative_Size n)
    {
      n.message();
    }
  }
  T &operator[](int i)
  {
    cout << "In 1" << endl;
    return elem[i];
  }
  const T &operator[](int i) const
  {
    cout << "In 2" << endl;
    return elem[i];
  }
  int getSize() const
  {
    try
    {
      if (size > 0)
        return size;
      else
        throw Negative_Size();
    }
    catch (Negative_Size n)
    {
      n.message();
    }
  }
  void print() const
  {
    cout << "Printing array elements:" << endl;
    for (int i = 0; i < size; i++)
    {
      cout << elem[i] << endl;
    }
  }
};
int main()
{
  Vector<int> v1(-1);
  Vector<double> v2(5);
  v2.print();
  cout << "Size of the array is: " << v2.getSize() << endl;
}