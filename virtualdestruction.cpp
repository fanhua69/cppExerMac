#include <iostream>

using namespace std;

class BaseA
{
public:
  BaseA()
  {
    m_pData = new int [10];
  }
  ~BaseA()
  {
    if( m_pData )
    {
      delete []m_pData;
      m_pData = NULL;
    }
  }

  int *m_pData ;
};


class DerivedA : public BaseA
{
public:
  DerivedA()
  {
    name_ = new string("NULL");
  }
  
  ~DerivedA()
  {
    delete name_;
  }

private:
  string* name_;

};

int virtualdestruction()
{
  BaseA * d1 = new DerivedA();
  delete d1;
  
  
  class B
  {
  };
  class C : public B
  {
  };
  class D : public B
  {
  };
  D* pD = new D();//pD的静态类型是它声明的类型D*，动态类型也是D*
  B* pB = pD;//pB的静态类型是它声明的类型B*，动态类型是pB所指向的对象pD的类型D*
  C* pC = new C();
  pB = pC;//pB的动态类型是可以更改的，现在它的动态类型是C*
  
  return 0;


}


