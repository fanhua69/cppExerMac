
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

const int mmm = 1000;
void lamda()
{
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  auto p = [](int n)
  {
    cout << n << endl;
  };

  std::for_each(std::begin(v), std::end(v), p);
  
  auto is_odd = [](int n)
  {
    return n % 2 == 1;
  };

  auto pos = std::find_if(std::begin(v), std::end(v), is_odd);
  if ( pos != std::end(v) )
    std::cout << *pos << std::endl;

  static int n1 = 100;

  std::function<int(int)> fd = [&fd](int n)
  {
     int mmmm = mmm ;
     mmmm++;
    return n < 2 ? 1 : fd(n - 1) + fd(n - 2);
  };

  for(int i=0;i<10;i++)
  {
    cout << fd(i) << endl;
  }
}