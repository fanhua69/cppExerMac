

#include <iostream>
using namespace std;

//��XΪN * N���������С����X�ĵ�i��ȫ�����㣬�����i�������ֻһ�У������С��i .

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



