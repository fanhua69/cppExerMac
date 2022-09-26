
#include "templateextern.h"

extern template class MyClass<int>;
extern template class MyClass<int>;    // not allowed
extern template class MyClass<int>;    // not allowed

extern template class MyClass<float>;  // OK

void templateextern()
{
  MyClass<int> a;
  int c = 1,d = 2;
  a.swap(c,d);
}