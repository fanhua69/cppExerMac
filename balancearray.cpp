
int getBalanceArray(int array[], int n)
{
  int leftLoc = 0;
  int rightLoc = (n - 1);
  int sumRight = array[rightLoc];
  int sumLeft = array[leftLoc];

  while ( leftLoc < rightLoc )
  {
    if ( sumRight > sumLeft )
    {
      leftLoc++;
      sumLeft += array[leftLoc];
    }
    else
    {
      rightLoc--;
      sumRight += array[rightLoc];
    }
  }

  if ( (sumRight + array[rightLoc - 1]) == sumLeft )
  {
    return rightLoc--;
  }
  else if ( (sumLeft + array[leftLoc + 1]) == sumRight )
  {
    return leftLoc++;
  }
  else
  {
    return (leftLoc + rightLoc)/2;
    // return floating point number location in the middle of the 2 locations
  }
}

void getBalanceArrayMain()
{
  int a[]={1,2,3,4,5,6,7,8,9,10,11};
  int n = sizeof(a)/sizeof(int);

  int i = getBalanceArray (a,n);
}