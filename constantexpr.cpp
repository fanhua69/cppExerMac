

#include <iostream>
#include "constantexpr.h"
#include <tuple>
#include <vector>

class testc
{
  static void test(const int *p)
  {
  }
};

template <typename T>
constexpr T PI = 3.14159265;

constexpr double getConstant()
{
  return  PI<double> *11;
}


constexpr int getIntConstant()
{
  return  PI<int> * 11;
}

int NN[getIntConstant()];

void constantexpr()
{ 
  //const MyClass3 s;
  //MyClass3 s1;
  //s1.m = 1;

  //g_mData = 134;

  //int n =1'0'0'000'013;

  //auto lam = [](auto x, auto y){ return x+y;};

  //double d = getConstant ();
  //int f = getIntConstant ();

 // std::tuple<string,string,int> i3tuple ;//{"foo","bar",7};
  typedef std::tuple<char *, char *, int> i3tuple;

  std::vector <i3tuple> v;
  v.push_back(i3tuple("foo", "bar", 7));
  v.push_back(i3tuple("foo2", "bar2", 7));


  for ( i3tuple t : v )
  {
    std::cout << std::get<0>(t) << ' ';
    std::cout << std::get<1>(t) << ' ';
    std::cout << std::get<int>(t) << '\n';
  };
}