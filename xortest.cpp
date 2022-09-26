



void xortest()
{
  unsigned int a[]={1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,9};

  unsigned int n = 0;

  for(int i=0;i<sizeof(a)/sizeof(int);i++)
  {
    n ^= a[i];  
  }


}