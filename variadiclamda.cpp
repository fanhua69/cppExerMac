

#include <iostream>

using namespace std;

template <class F, class ... Args>
void expand (const F& f, Args && ...args)
{
  initializer_list<int>{ ( f(std::forward < Args> (args)),0)...};
}

template <typename _Tx, typename _Ty>
auto multiply(_Tx x, _Ty y) //->decltype(_Tx*_Ty)
{
  //auto a;
  auto a4 = 10, a5 = 20, a6 = 30;//正确
  //auto b4 = 10, b5 = 20.0, b6 = 'a';//错误,没有推导为同一类型

  return x*y;
}

void variadiclamda()
{
  double s  = multiply (12,3);
  cout << s;
}