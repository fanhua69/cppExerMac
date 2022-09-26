
#include <iostream>
#include <memory>

constexpr int getconst()
{
  return 1;
}

constexpr struct MyType
{
  //constexpr MyType(int x):i(x)
  //{}
  int i;
  int j;
};

constexpr MyType mt = {10};

int auto_ptr1()
{
  //unique_ptr<int> p(new int);

  //int * pp = p.get();

  //*pp = 1002;

  MyType n1 = mt;

  //std::cout << "p points to " << *p.get() << '\n';

  unsigned int n = 9999;
  unsigned int m = n ^ 123;
  m = m^ 123;

  enum class jjj :char
  {
    sky = getconst ()+10,
    earth = getconst () +11
  };

  jjj mm = jjj::sky;
  int ll =(int) mm;
  if(mm >jjj::earth)
  {
  }



  std::pointer_safety l = std::get_pointer_safety();
  return 0;
}