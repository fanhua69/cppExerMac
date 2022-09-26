

#include <iostream>

using namespace std;

string operator""_s(const char * sz, size_t n)
{
  return string { sz, n };
}


constexpr long double operator"" _deg(long double deg)
{
  return deg*3.141592 / 180;
}

struct mytype
{
  mytype(double m) :m(m)
  {
  }
  double m;
};

mytype operator"" _mytype(long double n)
{
  return mytype(n);
}

struct MyComplex
{
  MyComplex(long double a): r(a)
  {
  }

  MyComplex(long double a, long double b) : r(a),i(b)
  {
  }

  double r;
  double i;
};

MyComplex operator ""_z(long double d)
{
  return MyComplex(0,d);
}

void userdefinedliteral()
{
  int n = 1'000'000;
  int n1 = __cplusplus;
  string sss = "qrweqrew"_s;
  MyComplex c = 1012321.00_z;
  return;
}