#include<iostream>
using namespace std;

class Element
{
  private:
    int x;
    int y;
    int *buf;
  public:
     Element()
     {
       x=1;
       y=2;
       buf= new int;
     }
     Element(int x1, int y1)
     {
       x=x1;
       y=y1;
       buf = new int;
     }
     Element(Element &&source)
     {
       cout << " move constructor called\n";
        x = source.x;
        y = source.y;
        buf = source.buf;
        //make sourc buf null
        source.buf = nullptr;
     }
     Element& operator=(Element &&source)
     {
       cout << "move assignment called\n";
        x = source.x;
        y = source.y;
        buf = source.buf;
        //make source buf null
        source.buf = nullptr;
       retrun *this;
     }
     int Getx()
     {
       return x;
     }
  
};
    

template<class T>
class ElementVec
{
  private:
   T* buf;
   int size;
   int capacity;
  public:
     ElementVec()
     {
       size=0;
       capacity=1;
       buf = new T[1];
     }
     void push_back(T element)
     {
       if ( size == capacity)
       {
         T *temp = new T[2*capacity];
         memcpy ( temp , buf , capacity);
         delete[] buf;
         capacity *= 2;
         buf = temp;
       }
       buf[size] = std::move(element);
       size++;
  }
  
  void print()
  {
    for( int i=0; i<size;i++)
       cout << buf[i].Getx()<<endl;
  }
};

int main()
{
  ElementVec<Element> v;
  v.push_back(Element(1,2));
  v.push_back(Element(5,6));
  v.print();
}


