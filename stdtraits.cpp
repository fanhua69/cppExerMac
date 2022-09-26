

#include <iostream>
#include <vector>

//using namespace std;


//·º»¯
template <typename T1, typename T2>
struct is_myvoid
{
  static const bool value = false;
};

//ÌØ»¯
template <>
struct is_myvoid<std::vector<int>, int*>
{
  static const bool value = true;
};

template <typename T1>
struct is_myvoid<const T1 *, float>
{
  static const bool value = true;
};

int stdtraits()
{
  std::cout <<is_myvoid<int,int>::value << std::endl;
  std::cout <<is_myvoid<void,void>::value << std::endl;
  return 0;
}