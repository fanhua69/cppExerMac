
#include "stdio.h"

char * sc(char *des, const char * src)
{
  if ( des == NULL || src == NULL )
  {
    return NULL;
  }

  if ( des == src )
  {
    return des;
  }

  char *t = des;

  while ((*des++ = *src++) != '\0');
  //while ( (*des++ = *src++) != '\0' );
  while(*src!=0)
  {
    char ss = (*des = *src);
    des++;
    src++;
  }

  return t;
}

void strcpy()
{
  char s1[11];
  char s2[11]={'a','b','c','d','e','f','g','h','i','j','\0'};
  sc (s1,s2);
}
