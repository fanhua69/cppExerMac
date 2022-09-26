
/*
6. Given a list of numbers, find two valid indexes such that the numbers sum to N.
// 1, 6, 5, -3    N=7 -> true,    N=2 -> true,   N=3 ¨C> false
*/

#include <unordered_map>

std::pair <int, int> find2indexesforsum(int array[], int n, int sum)
{
  std::unordered_map<int, int> indices;
  for(int i=0;i<n;i++)
  {
    indices[array[i]] = i;
  }

  for(int i=0; i<n;i++)
  {
    std::unordered_map<int,int>::iterator it = indices.find(sum-array[i]);
    if(it != indices.end())
    {
      return std::pair<int,int> (i,it->second);
    }
  }

  return std::pair<int,int>(-1,-1);
}


void find2indexesforsumMain()
{
  int array[] = { 1,2,3,4,5,6,7,8,9,-1,-2,-3};
  std::pair<int,int> indices = find2indexesforsum(array, sizeof(array)/sizeof(int),5);
}
