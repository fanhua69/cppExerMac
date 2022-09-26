
#include <iostream>
#include <string>
using namespace std;

void rawstringliterals()
{
  std::string s = R"( First Line . 
                      "Second Line.)";

  std::cout << s << endl;
}