
#include <iostream>
using namespace std;

class base1
{
public:
  int a;
  int b;
  base1()
  {
    a = 10;
    b = 20;
  }
  virtual void fun()
  {
    fun2();
  }
  void fun2()
  {
    cout << a << b << endl;//line 3
    cout << this->a << this->b << endl; //line 4
  }
};

class derive1 :public base1
{
public:
  int a;

  using base1::base1;

  derive1():base1()
  {
    a = 30;
    base1::a = 20;
    b = 40;
  }

  void fun()
  {
    cout << this->a << this->b << base1::a << endl;
    fun2();//line 2
  }
} bb,nn;

class aaa
{
public:
  int x;
  int y;
};

void variableoverride()
{
  aaa q =  {1};

  base1 *b = new derive1;
  b->fun();//  line 1
  delete b;
  return;
}