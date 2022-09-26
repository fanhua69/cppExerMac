
#include <string>
class aaa
{
};

struct A
{
  explicit A(int a)
  {}

  //implicit conversion to int
  explicit operator int()
  {
    return 100;
  }

  //explicit conversion to std::string
  explicit operator aaa()
  {
    return aaa();
  }
};

void explicitoprator()
{
  A a = A(10);
  int i = (int)a;  //ok - implicit conversion 
  aaa b = aaa(a); //error - requires explicit conversion 
}