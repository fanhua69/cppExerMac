
#include <vector>
using namespace std;

// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
  // write your code in C++14 (g++ 6.2.0)

  int size = A.size ();
  int leftsum ,rightsum ;

  int sum = 0;
  for(int n:A)
  {
    sum+=n;
  }
  
  rightsum = sum - A[0];
  leftsum = 0;
  int equipoint = 0;

  std::vector<int> result;
  while(true)
  {
    leftsum += A[equipoint];
    equipoint++;

    if ( equipoint >= size )
    {
      break;
    }

    rightsum-=A[equipoint];


    if(leftsum == rightsum)
    {
      result.push_back (equipoint);
    }
  }


  if(result.size ()> 0)
  {
    return result[0];
  }
  else 
  {
    return -1;
  }
}


void equilibrium()
{
  std::vector<int> a =
  { -1,3,-4,5,1,-6,2,1};
  solution(a);

}