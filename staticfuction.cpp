

#include <iostream>
#include <string>
#include <map>
#include <vector>

class staticC
{
public:

  static void check()
  {
    m_n = 10;
  }

private :

  static int m_n;
};