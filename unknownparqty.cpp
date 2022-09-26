

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdarg.h>


void unknown(int num, ... )
{
  va_list ap;
  va_start(ap,num);

  int max = -0x7fffffff;

  for(int i=0;i<num;i++)
  {
    int t = va_arg(ap,int);
    if(t> max)
    {
      max = t;
    }
  }

  va_end(ap);

 std::cout << max;

}