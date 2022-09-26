

#include <stdio.h>

//__attribute__
int  add(int x) // __attribute__((constructor))
{
  printf("%s(%d)\n", __FUNCTION__, x);
  return x + 1;
}

int  add2(int x)
{
  printf("%s(%d)\n", __FUNCTION__, x);
  return x + 1;
}

void add3[[noreturn]]()
{
  return;
}

int attributeconst()
{
  int i, j;

  i = add(10);
  j = add(10);

  printf("%d %d\n", i, j);

  i = add2(10);
  j = add2(10);

  printf("%d %d\n", i, j);

  return 0;
}