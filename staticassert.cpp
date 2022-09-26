

#include <iostream>
#include <type_traits>

template <typename T>
class staticasserttemplate
{
  static_assert(std::is_integral<T>::value, "parameter must be an integer\n");
};

int staticassert()
{

  staticasserttemplate<int> intT;      // compile OK
  staticasserttemplate<char> charT;    // compile OK
  //staticasserttemplate<float> ST;          // compile error
  return 0;
}