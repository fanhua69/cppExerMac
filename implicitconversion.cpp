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

  
}; // B公有继承自A，可以是间接继承的

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
}; // B实现了隐式转化为A的转化

class D
{
};

class AA
{
public:
  AA(const D&)
  {
  }

}; // A实现了non-explicit的参数为B（可以有其他带默认值的参数）构造函数


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
  cout << "str字符长度为: " << sizeof(str) / sizeof(str[0]) << endl;

}
//A& operator= (const A&); // 赋值操作，虽不是正宗的隐式类型转换，但也可以勉强算一个
