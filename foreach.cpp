
#include <iostream>
using namespace std;



class B
{
public:
  virtual void f(int)
  {
    std::cout << "B::f" << std::endl;
  }
};

class D : public B
{
public: 
  virtual void f(int) override
  {
    std::cout << "D::f" << std::endl;
  }
};

class F : public D
{
public:
  virtual void f(int) override
  {
    std::cout << "F::f" << std::endl;
  }
};



void foreachtest ()
{
  int a[]= {1,2,3,4,5,6,7,9};

  //for each is a supported extension in VS's native c++ ¨C Nikos Athanasiou May 3 '14 at 21:08
  int sum = 0;
  for each(int i in a)  // VC ++ ( for each)
  {
    sum += i;
  }

  int arr[] = { 1,2,3,4,5 };
  for ( auto &e : arr)
  {
    e = e*e;
  }
  

  //for each is a supported extension in VS's native c++ ¨C Nikos Athanasiou May 3 '14 at 21:08
  sum = 0;
  for each (auto e in arr)
  {
    sum +=e*e;
  }
}