

#include <stdio.h>
#include <string>

int a = 0; //全局初始化区
char *p1; //全局未初始化区
void stackheap()
{
  int b; //栈
  char s[] = "abc"; //栈
  char *p2; //栈
  char *p3 = "123456"; //123456{post.content}在常量区，p3在栈上
  static int c = 0; //全局（静态）初始化区
  p1 = (char *)malloc(10); //分配得来得10字节的区域在堆区
  p2 = (char *)malloc(20); //分配得来得20字节的区域在堆区
  strcpy_s(p1,7, "123456");
  //123456{post.content}放在常量区，编译器可能会将它与p3所指向的"123456"优化成一块
}