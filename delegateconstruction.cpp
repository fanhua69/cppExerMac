
#include <iostream>

using namespace std;

class A
{
public:
  A() = default;

  A(int x1, int y1, int z1)
    :x(x1), y(y1), z(z1)
  {
    int m = 0;
  }

private:
  int x = 1;
  int y;
  int z;

};

class B : public A
{
public:
  using A::A;
  B()=default;

};

class C :public B
{
public:
  using B::B;
  int z;
};

void delegteconstruction()
{
  B b;
  C c(1, 2, 3);
  c.z = 4;
  c.z = 5;
}