#include <iostream>

//�˺�չ����������printf("123"),printf("456");  
#define TRACE_CMH_1 (printf("%s(%d)-<%s>: ",__FILE__, __LINE__, __FUNCTION__), printf)  

//�˺�չ����������printf("%d""%d", 1, 2);  
#define TRACE_CMH_2(fmt,...) \
printf("%s(%d)-<%s>: "##fmt, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)


int count = 1;

class CBase
{
public:
  CBase()
  {
    //��ӡ��ǰ�������ļ����кš��������Լ�������Ϣ��  
    TRACE_CMH_2("BASE: [%d]\n", count++);
  }
};

class CSub : public CBase
{
public:
  CSub()
  {
    //��ӡ��ǰ�������ļ����кš��������Լ�������Ϣ��  
    TRACE_CMH_1("SUB: [%d]\n", count++);
  }
};

void stringc99()
{
  CSub sub;

  return ;
}