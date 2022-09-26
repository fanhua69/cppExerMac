#include <stdio.h>
#include <iostream>

using namespace std;

class A
{
public:
  int m;
  void print()
  {
    cout << "A\n";
  }
};

void bitoper()
{
  A *pa = NULL;
  pa->print();
}