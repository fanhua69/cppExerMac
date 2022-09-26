
#include <map>

// Clear a map in one iteration with map value containing a pointer objects.

void mapCleanMain()
{
  std::map<int, double *> m;

  m[0] = new double(0) ;
  m[1] = new double(1);
  m[2] = new double(2);
  m[3] = new double(3);
  
  
  double *p = NULL;
  std::map<int,double *> :: iterator it = m.begin();
  while(it!=m.end())
  {
    if(it->second)
    {
      p = (double*)(it->second);
      int nn = 2;
      delete p;
      it->second = NULL;
    }

    it = m.erase(it);
  }

}