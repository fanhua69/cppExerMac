
#include <iostream>
//#include <string>
//#include <map>
#include <vector>

void testv()
{
  std::vector<int> v;
  v.reserve (10);
  v.push_back (1);
  v.push_back (12);
  v.push_back (15);
  int n = v.capacity ();
  n = v.back ();
  n = v.front ();

  try
  {
    for(int i=0;i<4;i++)
    {
      int n = v.at(i);
    }
  }
  catch(const std::exception &e)
  {
    std::cout << e.what() <<std::endl;
  }

  v.pop_back ();


}