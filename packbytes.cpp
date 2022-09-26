
#include "stdio.h"

//#pragma pack(push, 1)  //后面可改为1, 2, 4, 8
struct StrtE
{
char m1;
long m2;
      
};
//#pragma pack(pop)

void packbytes()
{
  int a;
  int b;
  int c;
  int d1;
  int d2;

  int d[2];
  struct StrtE s;

  printf("a    address:   %d\n", &a);
  printf("b    address:   %d,%d\n", &b, (char*)&b - (char*)&a);
  printf("c    address:   %d,%d\n", &c, (char*)&c- (char*)&b);
  printf("d1   address:   %d,%d\n", &c, (char*)&d1 - (char*)&c);
  printf("d2   address:   %d,%d\n", &c, (char*)&d2 - (char*)&d1);

  printf("d[0] address:   %d,%d\n", &(d[0]), (char*) &(d[1])- (char*)&(d[0]));
  printf("d[1] address:   %d,%d\n", &(d[1]), (char*)&s- (char*) &(d[1]));
  printf("s    address:   %d,%d\n", &s, (char*)&(s.m2)- (char*)&s);
  printf("s.m2 address:   %d,%d\n", &(s.m2), &(s.m1) );


  printf("a    address:   %p\n", &a);
  printf("b    address:   %p\n", &b);
  printf("c    address:   %p\n", &c);
  printf("d[0] address:   %p\n", &(d[0]));
  printf("d[1] address:   %p\n", &(d[1]));
  printf("s    address:   %p\n", &s);
  printf("s.m2 address:   %p\n", &(s.m2));
 
}