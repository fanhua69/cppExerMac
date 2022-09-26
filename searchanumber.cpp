

#include <iostream>
#include <map>

using namespace std;

int32_t findMostRepeated(int32_t arr[], int32_t len)
{
  int32_t justYou = 0, existsTime = 0, i = 0;
  for ( i = 0; i < len; i++ )
  {
    if ( existsTime == 0 )
    {
      justYou = arr[i];
      existsTime++;
    }
    else
    {
      if ( justYou == arr[i] )
      {
        existsTime++;
      }
      else 
      {
        existsTime--;
      }
    }
  }

  return justYou;
}

void searchanumber()
{
  int32_t arr[] = { 10, 1, 3, 1, 2, 1, 1, 6, 1, 1 };
  printf("mostRepeated = %d\n", findMostRepeated(arr, 10));
  return;
}



