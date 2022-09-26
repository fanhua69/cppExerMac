

#include <iostream>

using namespace std;

struct MyClass1
{
  int m ;
  double n; 
};



ostream & operator << (ostream &o, const MyClass1 &p)
{
  o << p.m << endl;
  o << p.n << endl;
  return o;
}

void initializerlist()
{
  auto kk = 1232131.3214;
  MyClass1 c[]={{1,2},{2,3},{3,4}};

  cout << c[0];
}