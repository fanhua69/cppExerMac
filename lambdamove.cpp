
#include <memory>
#include <iostream>


[[deprecated("sdafdsafdsafdsasdffasdfsadf")]]
void fff()
{
};

//class[[deprecated("use another new class")]]ffff
//{}

int lambdamove()
{
  std::unique_ptr<int> p(new int);
  int x = 5;
  *p = 11;
  auto y = [p = x+1]()  // c++14 initialized captures
  {
    int n = 12;
    std::cout << "inside: " << p << "\n"; 
  };

  y();

  std::cout << "outside: " << *p << "\n";
  return 0;
}