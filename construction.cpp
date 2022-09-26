
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class car
{
public:
  car()
  {
    cout << "in car " << endl;
  }

  car(car &a)
  {
      cout << "in car &a " << endl;
  }

  car(const car &a)
  {
      cout << "in const car &a " << endl;
  }

  int m_i;
};

void construction()
{
  const car a;
  car b(a);
}
