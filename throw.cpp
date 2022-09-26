
#include <iostream>


#include "stdio.h"
#include "vcruntime_exception.h"
#include "vcruntime.h"


struct aaa
{
  int a = 1;
  double b{1.2};
};

class ttt
{
  static const int a = 0;
  float aa = 0;
  double bbb = 0;
  float c {1};
  const float cc = 1;
  
};

const int aaaaa = 0;

//void * operator new (std::size_t) throw(std::bad_alloc)
//{
//  std::cout << __cplusplus;
//  return NULL;
//}