

#include <vector>

template <typename T, typename T2>
struct FooBar
{
};

template<typename T>
struct Global
{
};

void templatelocaltypes()
{
  struct Local
  {
  };
  std::vector<Local> a;
  //FooBar<Local, Global<int>> k;
}