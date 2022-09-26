
#include <iostream>
class A
{
  virtual void func(){};
};

class B1: virtual  public A
{
  virtual void foo(){};
};

class B2 : virtual  public A
{
  virtual void foo(){};
};

class B3 : virtual  public A
{
  virtual void foo(){};
};

class CCCC : virtual public B1 , virtual  public B2 , virtual public B3
{
  virtual void foo(){};
};

class D : virtual  public CCCC
{
  virtual void foo(){};
};

void virtualinherit()
{
  using namespace std;
  int n1 = sizeof(A);
  int n2 = sizeof(B1);
  int n21 = sizeof(B2);
  int n3 = sizeof(CCCC);
  int n4 = sizeof(D);

  CCCC ccc;

  std::cout << n1 << endl;
  std::cout << n2 << endl;
  std::cout << n21 << endl;
  std::cout << n3 << endl;
  std::cout << n4 << endl;
}