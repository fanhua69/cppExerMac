

#include <iostream>
using namespace std;


template <int N>
void testconst(int i)
{
  int n = N;
  if( i== N)
  {
    cout << 'A'<< N  <<endl;
  }
  else if( i >= 10)
  {
    cout << "ERROR" << endl;
  }
  else
  {
    testconst <N < 10 ? N+1: 0 > (i);
  }
}

void testconstmain()
{
  for(int i=0;i<12;i++)
  {
    testconst <0> (i);
  }
}