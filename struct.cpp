

#include <stdio.h>
struct data
{
  int a;
  unsigned short b;
  int c;
};


void StructureStore()
{
  data mData;
  mData.a = 0x04030201;
  mData.b = 0x0201;
  mData.c = 0x08070605;
  char *pData = (char *)&mData;
  printf("%d %d", sizeof(pData), (int)(*(pData + 4)));
  return;
}