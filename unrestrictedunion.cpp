
#include <string>

class Y
{
public:
  //constexpr Y()
  //{
  //}
};

union X
{
  int a;
  float b;
  Y x;
  static int &j;
  //X(){}
};

X x;

union U
{
  int i;
  float f;
  //std::string s;
};

U y;

void unrestrictedunion()
{
}