
// PROGRAM 2
#include <iostream>
using std::cout;

class Test
{
public:
  volatile const int x = 0;
  mutable int y =10;
  Test()
  {
  }
};

volatile static int a = 0;

void mutablemain()
{
  const Test t1;
//  t1.y = 8;
  cout << t1.x;
  int a = 10;

  [=]()mutable
  {
    a =10;
    t1.y =10;
  };

  return ;
}