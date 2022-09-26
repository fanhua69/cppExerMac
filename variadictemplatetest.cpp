
#include <iostream>
#include <math.h>
using namespace std;

template <int b>
int check()
{
  return b?  1: 0;
}

template <class T1>
void t(T1 a)
{
}

template <class T1, class ...T>
void t(T1 a, T ...b)
{
}

template <int  b,int c, int ...d>
int check()
{
  std::cout << __FUNCSIG__ << "\n";
  t(b, d...);
  int cc = b;
  int cc2 = c;

  int cc3 = sizeof...(d);
  int n2 = b + check<c, d...>() << 1;
  return n2;
}





// Enter your code for reversed_binary_value<bool...>()
template <bool a>
int reversed_binary_value()
{
  return a;
}

template <bool a, bool... d> 
int reversed_binary_value()
{
  return (reversed_binary_value<d...>() << 1) + a;
}




void variadictemplatetest()
{
  check <1,2,3,4,5> ();
}