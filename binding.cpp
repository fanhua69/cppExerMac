
#include <iostream>
using namespace std;

class A3
{
public : 
  A3()
  {
    m_dData = 3;
  }

  A3(const A3& a)
  {
    m_dData = a.m_dData;
  }


  void operator = (const A3& a)
  {
    m_dData =  a.m_dData;
  }

  virtual inline int tt()
  {
    return 0;
  }


  inline void fun(int);
  double m_dData;
};

class B3 : public A3
{
public:
  B3()
  {
    m_dDataB = 4;
  }

  B3(const B3& b)
  {
    m_dDataB = b.m_dDataB;
  }


  void operator = ( const B3& b)
  {
    m_dDataB = b.m_dDataB;
  }

  virtual inline int tt()
  {
    return 0;
  }



  double m_dDataB;
};

class C3 : public B3
{
public:
  C3()
  {
    m_dDataC = 5;
  }
  
  C3(const C3& c)
  {
    m_dDataC = c.m_dDataC;
  }

  void operator = (const C3& c)
  {
    m_dDataC = c.m_dDataC;
  }

  virtual inline int tt()
  {
    return 0;
  }

  inline int factorial(int n)
  {
    if ( !n ) return 1;
    else return n*factorial(n - 1);
  }

  double m_dDataC;
};

template <class Type> class Test
{
public:
  Test()
  {
  }

  template <class type2> 
  Test(const type2& t)
  {
    int m= 0;
  }
  
  template <class type2>
  void fun2(const type2& t)
  {
    int m = 0;
  }

  void f()
  {
    cout << "My Type is: " << typeid(*this).name() << endl;
  }
};

void binding()
{
  C3 b;
  C3 b1;
  b1 = b;
  
  C3 c(b1);

  A3* pa = &c;
  pa->tt();

  Test <int> a1;
  Test <int> a3;
  
  Test <char> ac2;
  a1 = a3;

  ac2 = a1;

}

