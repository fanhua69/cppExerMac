

#include <iostream>

using namespace std;

class testfunctor
{
public:
  testfunctor(int t)
  {
    m_t = t;
  }

  void operator ()(int adder)
  {
    m_t += adder;
  }

private :
  int m_t;
};


void functor()
{
  testfunctor t(10);

  t(12);

}