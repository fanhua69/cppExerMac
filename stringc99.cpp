#include <iostream>

//此宏展开后，类似于printf("123"),printf("456");  
#define TRACE_CMH_1 (printf("%s(%d)-<%s>: ",__FILE__, __LINE__, __FUNCTION__), printf)  

//此宏展开后，类似于printf("%d""%d", 1, 2);  
#define TRACE_CMH_2(fmt,...) \
printf("%s(%d)-<%s>: "##fmt, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)


int count = 1;

class CBase
{
public:
  CBase()
  {
    //打印当前行所在文件、行号、函数，以及其它信息。  
    TRACE_CMH_2("BASE: [%d]\n", count++);
  }
};

class CSub : public CBase
{
public:
  CSub()
  {
    //打印当前行所在文件、行号、函数，以及其它信息。  
    TRACE_CMH_1("SUB: [%d]\n", count++);
  }
};

void stringc99()
{
  CSub sub;

  return ;
}