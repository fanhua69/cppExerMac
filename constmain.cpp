

int testlinkage = 10;


void constmain()
{
  int data =10;
  int data2 = 20;
  const int *a = &data;
  int * const b = &data;
  const register int nnn;// __asm("ebx");

  const int *pppp= &nnn;

  int d1 = *pppp ;

  testlinkage  = 20;

  a = &data2;
  // b = &data2;  //error




}