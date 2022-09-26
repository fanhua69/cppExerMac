



#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class nRowOrder
{
public:
  void f(double )
  {
    cout << "in a double " << endl;
  }

  void f()
  {
    cout << "in a " << endl;
  }

  int m_i;
};

class b : public  nRowOrder
{
public:

  using nRowOrder::f;

  void f(int)
  {
    cout << "in b int " << endl;
  }

  string m_i;

};

class c  : public b
{
public:
  void f()
  {
    cout << "in c" << endl;
  }
};

class d : public c
{
public:
  void f()
  {
    cout << "in d" << endl;
  }
};


void poly()
{
  b * p = new b;
  p->f();
  p->f(2);
  p->f(2.3);

  p->m_i = 1;
  p->m_i = "asdfsfd";

  cout << p->m_i;
}
