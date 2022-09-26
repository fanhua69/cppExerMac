

#include <iostream>

using namespace std;

class B
{
public:
  B():x(),y(0),z(0)
  {
  }

  B(int x1,int y1,int z1)
    :x(x1),y(y1),z(z1)
  {
    int m = 0;
  }

private:
  int x;
  int y;
  int z;
};

class C:public B
{
public:
  using B::B;
  int z;
};

void constructorinheritance()
{
  B b;
  C c(1,2,3);
  c.z = 4;
  c.z = 5;
}