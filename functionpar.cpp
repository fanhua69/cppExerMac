

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class AddressBook
{
public:
  // using a template allows us to ignore the differences between functors, function pointers 
  // and lambda
  template<typename Func>
  std::vector<std::string> findMatchingAddresses(Func func)
  {
    std::vector<std::string> results;
    for ( auto itr = _addresses.begin(), end = _addresses.end(); itr != end; ++itr )
    {
      // call the function passed into findMatchingAddresses and see if it matches
      if ( func(&(*itr)) )
      {
        results.push_back(*itr);
      }
    }

    return results;
  }

  void func5(std::vector<double>& v, const double& epsilon)
  {
    std::transform(v.begin(), v.end(), v.begin(),
                   [epsilon](double d) -> double
    {
      if ( d < epsilon )
      {
        return 0;
      }
      else
      {
        return d;
      }
    });
  }

  std::vector<std::string> _addresses;
};


bool search(std::string *s)
{
  return true;
}

void funtionpar()
{
  int a=0,b1=1;
  bool (*fun)(std::string *s) = search ;
  void (*fun2)(int, int) = [](int g, int h){cout << "hello, world!";};
  
  auto func3 = [a,&b1](int g, int h)
  {
    cout << "hello, world!\n";
  };

  [a, &b1]()
  {
    cout << "hello, world!\n";
  }();

  fun2(a,b1);

  int aa = [](int b)
  {
    int r = 1; 
    
    while ( b > 0 ) 
      r *= b--; 
    
    return r;
  }(5);

  cout << typeid(func3).name() << endl;

  AddressBook b;
  b._addresses ={"a","b","c","d","e","f","g"};
  b.findMatchingAddresses(search);
}