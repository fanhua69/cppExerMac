
#include "iostream"
using namespace std;

/// �볲����
/// </summary>
/// <param name="unsorted">��������</param>
/// <param name="maxNumber">���������е������,�������ָ���Ļ�</param>
/// <returns></returns>
void pogeon_sort(int unsorted[], int size, int pigeonHole[])
{
  for(int i=0;i< size;i++)
  {
    int n = unsorted[i];
    pigeonHole[n]++;
  }

  /*
  * pogeonHole[10] = 4; �ĺ�����
  * �ڴ�����������4��10����,ͬ������
  */
}

void pigeonsort()
{
  int x[] = { 99, 65, 24, 47, 47, 50, 99, 88, 66, 33, 66, 67, 31, 18, 24 };
  int pigeonHole [100]={0};

  pogeon_sort(x, sizeof(x)/sizeof(int), pigeonHole);
  for ( int i = 0; i < sizeof(pigeonHole )/sizeof(int); i++ )
  {
    for ( int j = 0; j < pigeonHole[i]; j++ )
    {
      cout << i<< ",";
    }
  }
}