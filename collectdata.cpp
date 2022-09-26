

#include <stdlib.h>
#include <memory>

const int m = 2000;
const int n = 3000;


unsigned char a[n];
unsigned char b[m];
unsigned char c[256];


void collectdata()
{
  for(int i = 0; i < m;i++ )
  {
    b[i]=128.0* rand()/ RAND_MAX ;
  }

  for ( int i = 0; i < n; i++ )
  {
    a[i] = 256.0 * rand()/ RAND_MAX ;
  }

  char exist[256];
  memset(exist,0,256);

  for(int i=0;i<m;i++)
  {
    int location = b[i];
    exist[location] = 1;
  }


  memset(c,0,256);
  int nNotexist = 0;
  for(int i=0;i<n;i++)
  {
    int location = a[i];
    if(!exist[location])
    {
      c[nNotexist] = a[i];
      nNotexist++;
    }
  }
}