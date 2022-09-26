
#include<cstdarg>
#include<iostream>
using namespace std;

int add(double pre, ...)  //��ͺ���
{
  va_list lista;

  double sum = 0;
  double s;

  sum += pre;

  va_start(lista, pre);

  do
  {
    s = va_arg(lista, double);
    sum += s;

  } while ( s > 0.0001 );   //�Զ�������������������Ϊ0

  va_end(lista);

  return sum;
}

int argv()
{
  cout << add(1.0, 2.0, 3.0 ,0) << endl;  //������0��β����Ϊ�����б�������ж������Ƕ���0ֹͣ
  return 0;
}
