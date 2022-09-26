

#include <iostream>

using namespace std;

double variadicmultiply()
{
  return 1;
}

template <typename T, typename ... Tr>
double variadicmultiply(T value, Tr ... values)
{
  return value * variadicmultiply (values...);
}

void variadicmultiplymain()
{
  double d = variadicmultiply(2,3,4);
  cout << d;
}

