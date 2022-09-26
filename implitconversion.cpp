

#include <iostream>

#ifdef PI
//
//int m = 0;

#endif

namespace co = std;

using co::cout;

class MyNum
{
public:
  constexpr MyNum(int n):m(n)
  {
  }

  explicit operator int()
  {
    return m;
  }

  explicit operator double ()
  {
    return m*2;
  }

  explicit operator bool()
  {
    return m > 10000;
  }

  int m;
};

#define SQUARE(x) ((x)*(x))

constexpr int getxx()
{
  return 4*3;
}
void implicitconversion()
{
  MyNum a = 123;
  MyNum b = 'H';
  MyNum c = 2134.1234;
  int *p = new int (134);
  MyNum d = reinterpret_cast<int>(p);

  if((bool)a == (bool)b)
  {
  
  }

  if(a)
  {
  
  }
  int n = (int)d;
  int n1 = 12;

  cout << n;

  const int * pp = &n;
  int * const ppp = &n;

  auto ss = __func__;
  auto ddd = __DATE__;
  auto ttt = __TIME__;
  auto lll = __LINE__;

  int mmm= 12 * 123;
  int n22 = mmm* 12;
  int mmmm = SQUARE(n22);


}