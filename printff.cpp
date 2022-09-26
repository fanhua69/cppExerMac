
#include <iostream>

void printff(const char *s)
{
  while ( *s )
  {
    if ( *s == '%' )
    {
      if ( *(s + 1) == '%' )
      {
        ++s;
      }
      else
      {
        throw std::runtime_error("invalid format string: missing arguments");
      }
    }
    std::cout << *s++;
  }
}

template<typename T, typename... Args>
void printff(const char *s, T value, Args... args)
{
  while ( *s )
  {
    if ( *s == '%' )
    {
      if ( *(s + 1) == '%' )
      {
        ++s;
      }
      else
      {
        std::cout << value;
        // call even when *s == 0 to detect extra arguments
        printff(s + 1, args...);
        return;
      }
    }
    std::cout << *s++;
  }
  throw std::logic_error("extra arguments provided to printf");
}

void printfff()
{
  int a=13;
  double d = 23.678;
  char *s = "ghgkgkhgkhj";

  printff("% ,  % , % , %\n",a,d,s);
}