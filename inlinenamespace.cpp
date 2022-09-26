
// You can use members of an inline namespace
// as if they were also members of any namespace
// in its enclosing namespace set

//Header.h  
#include <string>  

namespace Test
{
  namespace old_ns
  {
    std::string Func()
    {
      return std::string("Hello from old");
    }
  }

  inline namespace new_ns
  {
      std::string Func()
      {
          return std::string("Hello from new");
      }
  }
}

#include <string>  
#include <iostream>  

int inlinenamespace()
{
  //using namespace Test;
  //using namespace std;

  std::string s = Test::old_ns::Func();
  std::cout << s << std::endl; 

  s = Test::Func();
  std::cout << s << std::endl;


  return 0;
}