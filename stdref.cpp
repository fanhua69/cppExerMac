
// ref example
#include <iostream>     // std::cout
#include <functional>   // std::ref
#include <string>

int stdref()
{
  int foo(10);

  auto bar = std::ref(foo);
  
  std::string s = typeid(bar).name();

  ++bar;

  std::cout << foo << '\n';

  return 0;
}