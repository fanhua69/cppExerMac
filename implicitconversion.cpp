#include <iostream>

using namespace std;

class ABFG
{
public:
  ABFG()= default;
  ABFG(int m)
  {
    n = m;
  };
  int n;
};

class B : public ABFG
{
public:
  using ABFG::ABFG;

  
}; // B���м̳���A�������Ǽ�Ӽ̳е�

class C
{
public:
  int operator ()(int i,int j)
  {
    return m[i]*m[j];
  }
  operator ABFG() const
  {
    return ABFG(m[0]);
  };

  int m[10] ;
}; // Bʵ������ʽת��ΪA��ת��

class D
{
};

class AA
{
public:
  AA(const D&)
  {
  }

}; // Aʵ����non-explicit�Ĳ���ΪB��������������Ĭ��ֵ�Ĳ��������캯��


void implicitconversion2()
{
  B * pb = new B;
  C * pc = new C;

  C cc;

  int nnn = cc(2,3);


  ABFG *pa = pb;
  *pa = *pc;

  D d;
  AA aa = d;

  char str[] = "aBcDe";
  cout << "str�ַ�����Ϊ: " << sizeof(str) / sizeof(str[0]) << endl;

}
//A& operator= (const A&); // ��ֵ�������䲻�����ڵ���ʽ����ת������Ҳ������ǿ��һ��
