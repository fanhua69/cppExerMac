
#include <iostream>

using namespace std;

int bit(unsigned int x)
{
  int a = 2;
  int b = a << 2;

  int countx = 0; 
  while ( x )
  {
    countx++; 
    x = x&(x - 1);
  }

  std::cout << countx << std::endl;

  return countx;  
}

void bitoperation()
{
    int n = bit(8);
    cout << n << endl;
}

/*
4
100
011

8
1000
0111

7 
10110
10101
10100
10011
10010
10001
10000
01111
01110
01101

111
110
101
100

11010
16+8+2
10. ������ڡ����ϡ�����Ŀ�����?

a)   ��i nclude 
union 
{ 
int i;  
char x[2];  }
a;  
void main()
{ 
a.x[0] = 10;
a.x[1] = 1; 
printf("%d",a.i); 
}  �𰸣�266 (��λ�͵�ַ����λ�ߵ�ַ���ڴ�ռ�������Ox010A��   b)
*/