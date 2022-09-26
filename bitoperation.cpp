
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
10. 下面关于“联合”的题目的输出?

a)   ＃i nclude 
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
}  答案：266 (低位低地址，高位高地址，内存占用情况是Ox010A）   b)
*/