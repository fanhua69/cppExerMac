

#include "stdio.h"

//static union 
//{
//  int i;
//  char x[4];
//};


void uniontest()
{
  union asdf
  {
    int i;
    char c[4];
    asdf(){};
    ~asdf()
    {}
    int get()
    {
      return i;
    }

  } s;

  {
    s.c[0] = '1';
    s.c[1] = '2';
    s.c[2] = '3';
    s.c[3] = '4';
  }

  union
  {
    int i1;
    char x[4];
    int aaa;
  };

  i1 = 10;

  //MyUnion a;
  //a.i = 10;
  //a.x[0] = 10;
  //a.x[1] = 1;
  //a.x[2] = 1;
  //a.x[3] = 1;

  //int n  = sizeof(a);

  //printf("%d", a.i);
}

//答案：266(低位低地址，高位高地址，内存占用情况是Ox010A）   b)
/*

000000100001010


*/