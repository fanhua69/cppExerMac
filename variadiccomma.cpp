

#include <iostream>

using namespace std;

template <class T>
int r(T a)
{
  return a;
}

template <class ...Ts>
void expandargs(Ts... args)
{
  int array[] = { (args)... };
}


void variadiccomma()
{
  expandargs(1,2,3,4,5);
}