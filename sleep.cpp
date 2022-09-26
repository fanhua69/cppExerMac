#include "windows.h"

INT64 GetYYY()
{
  __asm
  {
    rdtsc;
  }
}
void sleepWindows()
{
  INT64 jj = GetYYY();
  while(true)
  {
    long long  n = GetTickCount ();
    for(int i=0;i<960000;i++)
    {
    }

   // Sleep(1);
  }
}