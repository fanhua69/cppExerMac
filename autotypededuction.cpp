

#include <typeinfo>
#include <iostream>


void autotypededuction()
{
  int k;
  std::cout << typeid(k).name();
} 