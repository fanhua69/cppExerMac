

#include <iostream>
using namespace std;

//令X为N * N的整数阵列。如果X的第i行全都是零，请输出i。如果不只一行，输出最小的i .

const int N = 10;
int x[N][N];

void gotoconsideredharmful()
{
  int linewithvalue = -1;
  for(int i=0;i<N;i++)
  {
    linewithvalue = -1;
    for(int j=0;j<N;j++)
    {
      if(x[i][j] != 0)
      {
        linewithvalue = i;
        break;
      }
    }

    if( linewithvalue != -1)
    {
      break;
    }
  }

  if(linewithvalue != -1)
  {
    cout << linewithvalue << endl;
  }
  else
  {
    cout << "no empty lines " << endl;
  }
}



