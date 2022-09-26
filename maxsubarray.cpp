

typedef struct
{
  unsigned left;
  unsigned right;
  int sum;
} max_subarray;

void find_maximum_subarray()
{
  int A[]={1,2,3,0,-1,-6,-8,4,5,6,-9,-10,-13,-20,8,9,10,-11,-21,-31,1,2,3,4,5,6,7,6,4,3};
  unsigned int low = 0;
  unsigned int high = sizeof(A)/sizeof(int)-1;

  max_subarray *suffixes = new max_subarray[high - low];

  suffixes[0].left = low;
  suffixes[0].right = low + 1;
  suffixes[0].sum = A[low];

  max_subarray *previous = 0;

  for ( unsigned int i = low + 1; i < high; i++ )
  {
    if ( suffixes[i - 1].sum < 0 )
    {
      suffixes[i].left = i;
      suffixes[i].right = i + 1;
      suffixes[i].sum = A[i];
    }
    else
    {
      previous = &suffixes[i - 1];
      suffixes[i].left = previous->left;
      suffixes[i].right = i + 1;
      suffixes[i].sum = previous->sum + A[i];
    }
  }

  max_subarray *max = &suffixes[0];

  for ( unsigned int i = low + 1; i < high; i++ )
  {
    if ( max->sum < suffixes[i].sum )
    {
      max = &suffixes[i];
    }
  }

  max_subarray maxr = *max;
  delete []suffixes;

  return;
}