
//��Ŀ����дһ�����򣬿���3���̣߳���3���̵߳�ID�ֱ�ΪA��B��C��
// ÿ���߳̽��Լ���ID����Ļ�ϴ�ӡ10�飬Ҫ�����������밴ABC��˳����ʾ���磺ABCABC��.���ε��ơ�

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
std::mutex mymutex;
std::condition_variable va;

char threadOrder = 'A';


void printID(char ID)
{
  for(int i= 0;i< 10;i++)
  {
    std::unique_lock<std::mutex> lk(mymutex);
    while( threadOrder != ID )
    {
      va.wait (lk);
    }

    std::cout << ID << std::endl;
    threadOrder++;
    if( threadOrder == 'D')
    {
      threadOrder = 'A';
    }
    va.notify_all ();
  }
}

class testfunction
{
public:
    int testfff(int n, string s)
    {
        return 0;
    }

    void operator ()()
    {
       int mm = 0;
    }
};

void threadrace()
{
  thread A(printID, 'A');
  thread B(printID, 'B');
  thread C(printID, 'C');

  testfunction f;
  thread D(&testfunction::testfff,testfunction(),10,"sadf");
  
  thread F(f);




  A.join();
  B.join();
  C.join();
}
