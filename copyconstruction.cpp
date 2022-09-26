
#include <iostream>

using namespace std;

class A1
{
public:
  A1() 
  {
    m =12314;
  };

  A1(const A1&a)
  {
      m = a.m;
  };

  A1(A1 &&a)  // useless, not used anywhere.
  {
      m = a.m;
  }

  void operator = (A1&& o)
  {
    m = o.m;
  }

  int m = 1234 ;
};


void copyconstruction()
{
  const A1 a;
  A1 b = a ;//std::move(a);
  A1 b1(a);//std::move(a));
  A1 c;
  c = A1();



}