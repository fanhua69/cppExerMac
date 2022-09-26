
#include <iostream>
#include <string>

using namespace std;

class test
{
public:
  char data[20];
  char& operator[](const unsigned __int64 index);
  const char& operator [](const unsigned __int64 index) const;
};
char& test::operator [](const unsigned __int64 index)////重载[]操作符，作为左值
{
  return data[index];
}
const char& test::operator [](const unsigned __int64 index) const////重载[]操作符，作为右值
{
  return data[index];
}

class ccc
{
public:
  ccc()
  {
    p = new int [100];

    for(int i = 0 ; i < 100 ; i++)
    {
      p[i] = i;
    }
  }

  ~ccc()
  {
    delete p;
  }
  int & operator ()(int m, int n)
  {
    int nn = m*10+n;
    return p[nn];
  }

  int  operator ++()
  {
    p[0]++;

    return p[0];
  }

  int operator ++(int)
  {
    int n = p[1];
    p[1]++;
    return n;
  }

  int *p;
};

void numbconv(string &s, int n, int b)
{
  if ( n == 0 )
  {
    s = "";
    return;
  }

  /* figure out first n-1 digits */
  numbconv(s, n / b, b);

  /* add last digit */
  char c = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n%b];
  s+=c;
}

double ppp(int a, int b, double c)
{
  return a*b*c;
};

void datachange(void)
{
  int i, base;
  string s ;

  int ss[12][2];
  int (*a)[2];

  double (*pe)[20];  // pointer to a data group of 20 elements;


  double (*pq)(int, int, double) = ppp; // function;
  double d = (*pq)(2,3,4);
  a = &ss[0];

  ccc p;
  int n = p(2,3);
  p(2,3) = 24;

  test aa;
  aa[1] = 'A';
  char ch = aa[1];

  ccc c;
  int nnn = ++c;
  int  nnnn = c++;




  base = 8;

  try
  {
    /*PLS set START and END*/
    for ( i = 98 ; i <= 98; i++ )
    {
      numbconv(s, i, base);
      cout << i << " = " << s << endl;
    }
  
    cin >> i;
  }
  catch(...)
  {
    cout << "Error happened." << endl;
  }

}
