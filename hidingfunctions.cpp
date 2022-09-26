

#include <iostream>

using namespace std;

class A11
{
public:
  virtual void fun(){};
  virtual void fun(int){};
  virtual void fun(int, double){}
  virtual void fun(string){}
  
};

class A2
{
public:
  virtual void fun()
  {
  };
};

class A3
{
public:
  virtual void fun()
  {
  };
};

class B1 :public A11// ,public A2,public A3
{
public:
  virtual void fun()
  {
  }

 // using A1::fun;
};

void hidingfunctions()
{
  B1 b;
  b.fun();
  A11 *p = new B1;
  p->fun();
  delete p;

  A11 *p2 = new A11;
  p2->fun();
  delete p2;


  // b.fun(1,2.3);

  //A1 *a1 = &b;
  //A2 *a2 = &b;
  //A3 *a3 = &b;

  //b.fun();
  //a1->fun();
  //a2->fun();
  //a3->fun();
}