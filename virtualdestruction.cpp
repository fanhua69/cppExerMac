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
  D* pD = new D();//pD�ľ�̬������������������D*����̬����Ҳ��D*
  B* pB = pD;//pB�ľ�̬������������������B*����̬������pB��ָ��Ķ���pD������D*
  C* pC = new C();
  pB = pC;//pB�Ķ�̬�����ǿ��Ը��ĵģ��������Ķ�̬������C*
  
  return 0;


}


