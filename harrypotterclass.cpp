#include <iostream>  

using namespace std;
#define N 100

int lesson[N][2]={0,0,17,19,15,18,13,15,11,13,11,12,8,9,1,7,1,8};   //��¼����ʱ�� �� �¿�ʱ��  
int num[N]; // ��¼�ϵ�N�ÿεĻ����ϵ����γ�  

int harrypotterlessons()
{
  int n = 8;
  int i, j;

  memset(num, 0, sizeof(num));
  num[n] = 1; //��һ�׶Σ����������һ�ÿεĻ�������Ͽ���Ϊ 1  
  int max1;
  for ( i = n - 1; i >= 1; i-- ) //�Ӻ���ǰ����  
  {
    max1 = 0;
    for ( j = i + 1; j <= n; j++ )  //������ i+1 �ÿ� �����һ����<span style="white-space: pre;">  </span>(��̬�滮�����ֲ�����)  
    {
      if ( lesson[i][1] <= lesson[j][0] && max1 < num[j] )    //�Ƚ�i���εĽ����ε�ʱ�� �� ��j����(j>i)�Ŀ�ʼʱ��  
      {
        max1 = num[j];
      }
    }
    //�Ѿ��ҵ��� �Ϲ���i����֮�� �����ϵĿε����ֵ  
    num[i] = max1 + 1;
  }

  for ( max1 = 0, i = 1; i <= n; i++ )
  {
    if ( max1 < num[i] )
    {
      max1 = num[i];
    }
  }

  printf("Hello,world!\n");

  cout << max1 << endl;

  return 0;
}
