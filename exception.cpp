
#include <iostream>
#include <exception>

using namespace std;

const int n33 = 10;



struct CT : public std::exception
{
  int m;
};


class CJ: public CT
{
public:
  int n;
};

void aaa() noexcept
{

}

void exceptionfun() throw(CT)
{
  int jj = 90;
  throw(CJ());
  throw(CT());
  int n = 1;
  throw(12.23);
  int m = n * 8;
}

void __declspec(nothrow) exceptionmain()
{
  char c;
  int *r = reinterpret_cast<int*>(&c); // forced conversion
  *r =11210;

  //r = static_cast<int*>(&c); // forced conversion
  *r = 11210;

  int * kk = const_cast<int *>(&n33);
  *kk = 20;


  CJ mmm;
  mmm.m = 10;
//  mmm.n = 11;
  try
  {
    try
    {
      exceptionfun ();
    }
    catch (int n)
    {
      cout << "Int :" << n;
    }
    catch(std::exception &e)
    {
      cout << e.what ();
    }
    catch (double f)
    {
      cout << "Double :" << f;
    }
    catch(...)
    {
      cout << "Nothing caught";
    }
  }
  catch(CT c)
  {
    cout << c.m;
  }

}