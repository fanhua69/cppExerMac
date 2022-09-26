/*
�Ƿ���ϤPOSIX���̱߳�̼���������Ϥ����д����������¹��ܣ�
1����һint��ȫ�ֱ���g_Flag��ʼֵΪ0��
2�� �����߳������߳�1����ӡ��this is thread1��������g_Flag����Ϊ1
3�� �����߳��������߳�2����ӡ��this is thread2��������g_Flag����Ϊ2
4�� �߳���1��Ҫ���߳�2�˳�������˳�
5�� ���߳��ڼ�⵽g_Flag��1��Ϊ2�����ߴ�2��Ϊ1��ʱ���˳�

�������C++11ʵ�֣�����std::future, std::promiseʵ��һ����ͬ��������μ���ǰ���һƪ���£�
*/


#include <iostream>
#include <mutex>

using namespace std;

static mutex myMutexP;
static mutex myMutexOut;
static std::condition_variable vaP;
static std::condition_variable vaFlagChanged;
static int g_flag  = 0;
static bool flagChanged = false;

static void printID (int &id)
{
  {
    std::unique_lock<mutex> lk(myMutexOut);
    cout << "This is thread " << id << endl;
  }
  
  {
    std::unique_lock<mutex> lk(myMutexP);
    g_flag = id;
    vaFlagChanged.notify_all();
  }

  if(id == 2)
  {
    vaP.notify_all ();
    {
      std::unique_lock<mutex> lk(myMutexOut);
      cout << "Thread 2 exit " << endl;
    }
    return ;
  }

  else
  {
    std::unique_lock <mutex> lk(myMutexP);
    while( g_flag  != 2)
    {
      vaP.wait (lk);
    }

    {
      std::unique_lock<mutex> lk(myMutexOut);
      cout << "Thread 1 exit " << endl;
    }

    return;
  }
}

void checkFlgChange()
{
  std::unique_lock <mutex> lk(myMutexP);
  while( g_flag == 0)
  {
    vaFlagChanged.wait (lk);
  }

  {
    std::unique_lock<mutex> lk(myMutexOut);
    cout << "flag changed to not zero" << endl;
  }

  int nflag = g_flag;
  while( g_flag == nflag)
  {
    vaFlagChanged.wait(lk);
  }

  {
    std::unique_lock<mutex> lk(myMutexOut);
    cout << "flag changed 1/2" << endl;
  }


  flagChanged = true;
}

void threadpromise()
{
  thread maint(checkFlgChange);
  

  int id =2;
  thread a(printID,std::ref(id));
  thread b(printID,std::ref(id));

  maint.join();
  a.detach();
  b.detach();

  while(!flagChanged )
  {
    std::this_thread::yield ();
  }

  {
    std::unique_lock<mutex> lk(myMutexOut);
    cout << "Main thread exit " << endl;
  }


  return;
}
