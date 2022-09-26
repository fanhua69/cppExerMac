




#include <iostream>
using namespace std;

class Aic
{
public:
  Aic (int a,int b)
  {
    m = a;
    n = b;
  };


  Aic (string a)
  {
    m = 13;
  };

  int m  = 12;
  int n = 13;

};

class Bic : public Aic
{
public:
  using Aic::Aic;

  Bic (string a):Aic(a)
  {
  }

  Bic(float a):Bic((int)a)
  {
  }
};

#include <vector>

void inheritedconstructor()
{
  std::vector<Aic >i{{1,2},{3,5}};

  Bic b ={1,2};
  Bic c(1);
  Bic d("fdwafa");
}