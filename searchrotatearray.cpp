

int binary_search_rotate_arry_me(int a[], int n, int x)
{
  int low = 0;
  int high = n-1;

  while(low <= high)
  {
    int mid = (low + high)/2;

    if(a[mid] == x)
    {
      return mid;
    }

    if(a[mid] > a[low])
    {
      if(x >= a[low] && x < a[mid])
      {
        high = mid -1;
      }
      else
      {
        low = mid + 1;
      }
    }

    else 
    {
      if(x > a[mid] && x <= a[high])
      {
        low = mid + 1;
      }
      else
      {
        high = mid -1;
      }
    }
  }

  return -1;
}
void searchRotateArray()
{
  int a[] = { 6,7,8,9,10,11,12,13,14,15,1,2,3,4,5};
  int n = binary_search_rotate_arry_me(a, sizeof(a)/sizeof(int), 4);
}
//int binary_search_rotate_arry(int *a, int n, int x)
//{
//  int low = 0, high = n - 1, mid;
//  while ( low <= high )
//  {
//    mid = low + ((high - low) >> 1);
//    if ( a[mid] == x )
//      return mid;
//
//    if ( a[mid] >= a[low] )
//    {//×ó±ßÓÐÐò  
//      if ( x < a[mid] && x >= a[low] )
//        high = mid - 1;
//      else
//        low = mid + 1;
//    }
//    else //ÓÒ±ßÓÐÐò  
//    {
//      if ( x > a[mid] && x <= a[high] )
//        low = mid + 1;
//      else
//        high = mid - 1;
//    }
//    //cout << low << " " << mid << " " << high << endl;  
//  }
//  return -1;
//}
