
typedef struct
{
  unsigned left;
  unsigned right;
  int sum;
} max_subarray;

void find_maximum_subarray_2()
{
  int A[] = { 1,2,3,0,-1,-6,-8,4,5,6,-9,-10,-13,-20,8,9,10,-11,-21,-31,1,2,3};
  unsigned int low = 0;
  unsigned int high = sizeof(A) / sizeof(int) - 1;

  max_subarray arrayPre;
  max_subarray arrayCurr;
  max_subarray arrayMax;

  arrayPre.left = low;
  arrayPre.right = low + 1;
  arrayPre.sum = A[low];

  arrayMax.sum = -9999999;

  for ( unsigned int i = low + 1; i < high; i++ )
  {
    if ( arrayPre.sum < 0 )
    {
      arrayCurr.left = i;
      arrayCurr.right = i + 1;
      arrayCurr.sum = A[i];
    }
    else
    {
      arrayCurr.left = arrayPre.left;
      arrayCurr.right = i + 1;
      arrayCurr.sum = arrayPre.sum + A[i];
    }

    if(arrayCurr.sum > arrayMax.sum)
    {
      arrayMax = arrayCurr;
    }

    arrayPre = arrayCurr;
  }

  int m = 0;

  return;
}