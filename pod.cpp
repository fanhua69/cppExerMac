
#include <type_traits>

struct B
{
  B(){};
};


struct C
{
  C() = default;
  C(int aa) : a(aa)
  {
  }
  int a;
};

struct D
{
  int a =0;  
};

void podmain()
{
  bool b = std::is_pod<B>::value;
  bool c = std::is_pod<C>::value;
  bool d = std::is_pod<D>::value;

}
