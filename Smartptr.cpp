#include<iostream>
using namespace std;

template <class T>
  class SmartPtr
  {
    private:
      T *ptr;
    
    public:
      SmartPtr(T *p=nullptr)
      {
        ptr = p;
      }
      ~ SmartPtr()
      {
        delete ptr;
      }
      T& operator *()
      {
        return (*ptr);
      }
       T* operator->()
       {
         retrun (ptr);
       }
    
  };

class Point
{
  int a;
  int b;
  public:
  Point()
  {
    a=1;
    b=2;
  }
  
  print()
  {
    cout << a << " " << b;
  }
};


int main()
{
  SmartPtr<Point> ptr(new Point());
  ptr->print();
}


