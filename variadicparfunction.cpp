
#include <iostream>

using namespace std;


template <class T, class...Ts>
void foo(T a, Ts... s)
{
  int n = sizeof...(s);
  cout << a << endl;
  foo(s...);
}

template <class...Ts>
void foo2(Ts...s,...)
{
}


template <class T>
void foo(T t)
{
  cout << t << endl;
}

void variadicparfunction()
{
  foo(1,2,3,4.5,'a',"gfgfdsg",143,656);
}