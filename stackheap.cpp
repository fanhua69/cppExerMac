

#include <stdio.h>
#include <string>

int a = 0; //ȫ�ֳ�ʼ����
char *p1; //ȫ��δ��ʼ����
void stackheap()
{
  int b; //ջ
  char s[] = "abc"; //ջ
  char *p2; //ջ
  char *p3 = "123456"; //123456{post.content}�ڳ�������p3��ջ��
  static int c = 0; //ȫ�֣���̬����ʼ����
  p1 = (char *)malloc(10); //���������10�ֽڵ������ڶ���
  p2 = (char *)malloc(20); //���������20�ֽڵ������ڶ���
  strcpy_s(p1,7, "123456");
  //123456{post.content}���ڳ����������������ܻὫ����p3��ָ���"123456"�Ż���һ��
}