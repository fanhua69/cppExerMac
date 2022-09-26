

#include <iostream>

using namespace std;


double variadicadd()
{
  return 0;
}

template <typename T, typename... Ts>
double variadicadd(T a, Ts... values)
{
  return a + variadicadd (values...);
}

void variadicaddmain()
{
  double d = variadicadd(1,2,3,4,5,6);
  cout << d;
}