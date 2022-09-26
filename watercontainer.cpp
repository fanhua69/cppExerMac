
#include <algorithm>

int findWaterVolOfContainer(int array[], int n)
{
  if(n < 3)
  {
    return 0;
  }

  int *pnLeftMaxHeight = new int[n];
  int *pnRightMaxHeight = new int [n];

  // find max height on the left:
  pnLeftMaxHeight[0] = array[0];
  for(int i=1;i<n;i++)
  {
    pnLeftMaxHeight[i] = std::max(array[i-1], pnLeftMaxHeight[i-1]);
  }

  pnRightMaxHeight[n-1] = array[n-1];
  for(int i = n-2;i>=0;i--)
  {
    pnRightMaxHeight[i] = std::max(array[i+1], pnRightMaxHeight[i+1]);
  }

  int nVol = 0;
  for(int i=0;i<n;i++)
  {
    int nCol = std::min(pnRightMaxHeight[i], pnLeftMaxHeight[i]) - array[i];
    if(nCol < 0)
    {
      nCol = 0;
    }
    nVol += nCol;
  }


  delete []pnRightMaxHeight;
  delete []pnLeftMaxHeight;

  return nVol;
}

void waterContainer()
{
  int array[] = { 3,0,0,2,0,4,0,0,1};
  int n = findWaterVolOfContainer(array,sizeof(array)/sizeof(int));
}