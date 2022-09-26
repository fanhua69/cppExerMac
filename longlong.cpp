
#include <stdio.h>
void longlong()
{
  int  num1 = 1000000000;
  long num2 = 1000000000;
  long long num3;
  num3 = 10000000000000000000;
  long long num4 = ~0;

  printf("%u %u %u\n", sizeof(num1), sizeof(num2), sizeof(num3));
  printf("%d\n %ld\n %lld\n %llu\n", num1, num2, num3, num4);
  return ;

}