
#include<cstdarg>
#include<iostream>
using namespace std;

int add(double pre, ...)  //求和函数
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

  } while ( s > 0.0001 );   //自定义结束条件是输入参数为0

  va_end(lista);

  return sum;
}

int argv()
{
  cout << add(1.0, 2.0, 3.0 ,0) << endl;  //必须以0结尾，因为参数列表结束的判断条件是读到0停止
  return 0;
}
