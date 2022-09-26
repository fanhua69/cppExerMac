

#include <iostream>

using namespace std;

typedef unsigned long long ulong;

template<class T>
class myBox
{
public:
  T a;
  template<class T> void print()
  {
    std::cout << a << endl;
  }
  template<> void print<bool>()
  {
    std::cout << (a ? "true" : "false") << endl;
  }
};

void templatespecialization()
{
  ulong n;

  n =10000000000000000000LL;

  myBox<bool> box = { true };
  box.print<bool>(); // "true"

  myBox <int > box1 = {141};
  box1.print<int> ();
}
