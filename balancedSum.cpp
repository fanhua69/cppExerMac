


#include <vector>

int balancedSum(std::vector<int> &sales)
{
  int size = sales.size ();
  if(size <3)
  {
    return -1;
  }

  int middle = 0;
  if(size %2 ==0)
  {
    middle = size / 2 - 1 ;
  }
  else
  {
    middle = size / 2;
  }

  int sumLeft = 0;
  int sumRight = 0;

  for(int i = 0; i < middle; i++)
  {
    sumLeft += sales[i];
  }


  for ( int i = middle+1; i < size; i++ )
  {
    sumRight += sales[i];
  }

  while(sumLeft < sumRight )
  {
    sumLeft += sales[middle];
    sumRight -= sales[middle+1];
    middle++;
  }

  while ( sumLeft > sumRight )
  {
    sumLeft -= sales[middle-1];
    sumRight += sales[middle];
    middle--;
  }

  if(sumLeft == sumRight)
  {
    return middle ;
  }
  else
  {
    return -1;
  }
}

void balancedSumMain()
{
  std::vector<int> sales = { 1,2,1};

  int n = balancedSum(sales);

}
