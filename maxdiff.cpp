
int findMaxDiff(int arr[], int n, int &iLow, int &iHigh)
{
  if( n < 1)
  {
    return 0;
  }

  int *pDiff = new int [n];
  pDiff[0] = 0;
  for(int i=1;i<n;i++)
  {
    pDiff[i] = arr[i]- arr[i-1];
  }

  int *pSubArraySum = new int[n];
  pSubArraySum[0] = 0;
  iLow = 0;
  iHigh = 1;
  for(int i=1; i<n;i++ )
  {
    if(pSubArraySum[i-1] > 0)
    {
      pSubArraySum[i] = pSubArraySum[i-1]+pDiff[i];
      iHigh = i;
    }
    else
    {
      pSubArraySum[i] = pDiff[i];
      iLow = i-1;
    }
  }

  int nMaxDiff = 0;
  for(int i=0;i<n;i++)
  {
    if(pSubArraySum[i] > nMaxDiff)
    {
      nMaxDiff = pSubArraySum[i];
    }
  }

  delete []pSubArraySum;
  delete []pDiff;

  return nMaxDiff;
}


void findMaxDiffMain()
{
  int array[10] = {1,2,3,2,1,0,-1,8,9,10};
  int iLow = 0;
  int iHigh = 0;
  int n=findMaxDiff(array,sizeof(array)/sizeof(int),iLow,iHigh);

}