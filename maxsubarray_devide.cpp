

void FIND_MAX_CROSSING_SUBARRAY(int A[],
                                int low, 
                                int mid, 
                                int high,
                                int &max_left,
                                int &max_right,
                                int &max_sum)
{
  int left_sum = -1;
  int sum = 0;
  max_left = mid;

  int i,j;
  for ( i = mid; i >= low; --i )
  {
    sum += A[i];
    if ( sum > left_sum )
    {
      left_sum = sum;
      max_left = i;
    }
  }

  int right_sum = -1;
  sum = 0;
  max_right = mid + 1;
  for ( j = mid + 1; j <= high; ++j )
  {
    sum += A[j];
    if ( sum > right_sum )
    {
      right_sum = sum;
      max_right = j;
    }
  }

  max_sum = left_sum + right_sum;
}

void FIND_MAXIMUM_SUBARRAY( int A[], 
                            int low, 
                            int high, 
                            int &max_low, 
                            int &max_high, 
                            int &max_sum)
{

  class AAA
  {
    char a;
    short n;
  };

  AAA a1[10];

  int n1 = sizeof(int);
  int n2 = sizeof(double);
  int n3 = sizeof(a1);

  int n = sizeof(AAA);


  if ( high == low )
  {
    max_low = low;
    max_high = high;
    max_sum = A[low];
    return; // 递归底层，开始回归
  }
  else
  {
    int mid = (low + high) / 2 ; // C语言整数计算方式，结果向下取整
    int left_low, left_high, left_sum;
    FIND_MAXIMUM_SUBARRAY(A, low, mid,left_low, left_high, left_sum);
    
    int right_low, right_high, right_sum;
    FIND_MAXIMUM_SUBARRAY(A, mid + 1, high, right_low, right_high, right_sum);

    int cross_low, cross_high, cross_sum;
    FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high, cross_low, cross_high, cross_sum);

    if ( left_sum >= right_sum && left_sum >= cross_sum )
    {
      max_low = left_low;
      max_high = left_high;
      max_sum = left_sum;
    }
    if ( right_sum >= left_sum && right_sum >= cross_sum )
    {
      max_low = right_low;
      max_high = right_high;
      max_sum = right_sum;
    }
    else
    {
      max_low = cross_low;
      max_high = cross_high;
      max_sum = cross_sum;
    }
  }
}



void FIND_MAXIMUM_SUBARRAY()
{
  int A[] = { 1,2,3,0,-1,-6,-8,4,5,6,-9,-10,-13,-20,8,9,10,-11,-21,-31,1,2,3 };
  unsigned int low = 0;
  unsigned int high = sizeof(A) / sizeof(int) - 1;

  int max_low, max_high, max_sum;
  FIND_MAXIMUM_SUBARRAY(A,low,high, max_low, max_high, max_sum);
}
