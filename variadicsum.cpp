

#include <iostream>

using namespace std;

double variadicsum()
{
  return 0;
}

template <typename... Ts>
double variadicsum(float value, Ts... values)
{
  return value + variadicsum(values...);
}

template <typename... Ts>
double variadicsum(char *value, Ts... values)
{
  return variadicsum(values...);
}

template <typename... Ts>
double variadicsum(int value, Ts... values)
{
  return value + variadicsum(values...);
}


void variadicsummain()
{
  char *c = "qewerq";
  double d = variadicsum (1,c,2,3);

  cout << d;
}

