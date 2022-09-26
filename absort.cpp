

#include <iostream>
#include "algorithm"
#include <functional>

using namespace std;

void absort(float *a, int n)
{
  int i =10;
  float j = 20;
  double k = 30;
  bool mm = false;
  std::function<bool(float,float)> ff = 
    [](float l, float r)->bool
    {
      int n1 = 10; return fabs(l) > fabs(r);
    };

  auto fff =
    [=, &i, &k,&mm](float l, float r) mutable ->bool
  {
     l -= j;
     r -= j;
     j++;
     i++;
     k++;
     mm  = true;
    return l < r;
  };

  std::sort(a,a+n,fff);

  int n3 =0;
};

void absort()
{
  float a[] = {1,3,-4,2,5,7,-9,-12,11};
  absort (a,sizeof(a)/sizeof(float));
}