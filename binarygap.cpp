
#include <iostream>

using namespace std;

int BITS[]=
{
  1,
  1<<1,
  1<<2,
  1<<3,
  1<<4
};


bool getbit(int N, int iBit)
{
  int NBIT = N & BITS[iBit];
  return (NBIT != 0);
}


static int solution(int N)
{
  bool n = getbit (N,3);

  return n;
}

void binarygap()
{
  //For example, given N = 1041 
  // the function should return 5,
  // because N has binary representation 10000010001 
  // and so its longest binary gap is of length 5.
  int n = solution (1041);
  cout << n << endl;
}