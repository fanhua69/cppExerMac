
#include <iostream>
#include <math.h>

using namespace std;

template <bool v>
int reversed_binary_value()
{
  return v;
}

template <bool a, bool c, bool ...digits>
int reversed_binary_value()
{
  int bits = sizeof...(digits);
  //if ( v == 1 )
  {
    //return pow(2, bits - 1);//
    return reversed_binary_value<c, digits...>();
  }
  //else
  //{
  //  return reversed_binary_value<digits...>();
  //}
  return 1;
}


template <int n, int...digits>
struct CheckValues
{
  static void check(int x, int y)
  {
    CheckValues<n - 1, 0, digits...>::check(x, y);
    CheckValues<n - 1, 1, digits...>::check(x, y);
  }
};

template <int...digits>
struct CheckValues<0, digits...>
{
  static void check(int x, int y)
  {
    int z = reversed_binary_value<digits...>();
    std::cout << (z + 64 * y == x);
  }
};

void variadictemplate()
{
  int x, y;
  cin >> x >> y;
  CheckValues<6>::check(x, y);
  cout << "\n";
}