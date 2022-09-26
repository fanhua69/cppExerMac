
#include <iostream>

using namespace std;

void move (int n, int a, int c)
{
  cout << "Moving " << n << " from " << a << " to " << c << "\n";
}

void hannoi(int n, int a, int b, int c)
{
  if( n == 1)
  {
    move(n, a, c);
  }
  else
  {
    hannoi (n-1, a, c,b);
    move(n, a, c);
    hannoi (n-1, b, a, c);
  }
}

void nRowOrder()
{
  int n = 3;
  hannoi (n, 1,2,3);

  cin >> n;
}