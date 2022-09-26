
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

class CTest
{
public:
  int m;
  int n;
  CTest(){ m = 12; n = 34;};
  CTest(int m_, int n_)
  {
    m = m_;
    n=n_;
  }
};
unique_ptr<CTest> make_int(int n)
{
  return unique_ptr<CTest>(new CTest(n,n+1));
}
void show(unique_ptr<CTest> & p1)
{
  cout << p1->m  << ',' <<p1->n << endl;
}


void smartpointer()
{
  vector<unique_ptr<CTest> > vp(10);
  for ( int i = 0; i < vp.size(); i++ )
  {
    vp[i] = make_int(rand() % 1000);              // copy temporary unique_ptr
  }
  vp.push_back(make_int(rand() % 1000));     // ok because arg is temporary
  std::for_each(vp.begin(), vp.end(), show);           // use for_each()

  CTest n1 = *vp[0];

  cout << vp[0]->m << endl;

  CTest *pt = new CTest;
  shared_ptr<CTest> *sp = new shared_ptr<CTest>(pt);

  weak_ptr <CTest> wp;

  wp = * sp;

  delete sp;

  cout << wp.use_count();
  if(wp.expired ())
  {
    int m = 0;
  }

  CTest * pp = vp[0].get();

  CTest n = *pp;

  if(vp[0])
  {
    int mm = 0;
  }
}