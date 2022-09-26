
#include <iostream>
#include <functional>
using namespace std;

int TestFunc(int a, char c, float f,string s)
{
  cout << a << endl;
  cout << c << endl;
  cout << f << endl;
  cout << s.c_str ()<< endl;

  return a;
}

int stdbind()
{
  auto bindFunc1 = bind(TestFunc, std::placeholders::_2, 'A', 100.1, std::placeholders::_1);
  bindFunc1(string("dsafasd"),10);

  cout << "=================================\n";

  //auto bindFunc2 = bind(TestFunc, std::placeholders::_2, std::placeholders::_1, 100.1);
  //bindFunc2('B', 10);

  //cout << "=================================\n";

  //auto bindFunc3 = bind(TestFunc, std::placeholders::_2, std::placeholders::_3, std::placeholders::_1);
  //bindFunc3(100.1, 30, 'C');

  return 0;
}