
#include "iostream"
using namespace std;

// A function that 'squares' a number; ie, multiples
// it by itself.
template <typename T>
T square(T t)
{
  return t * t;
}

// Our base case just returns the value.
template <typename T>
double power_sum(T t)
{
  return t;
}

// Our new recursive case.
template <typename T, typename... Rest>
double power_sum(T t, Rest... rest)
{
  return t + power_sum(square(rest)...);
}

void variadicfunction2()
{
  int n=  power_sum (2,4,6);
}