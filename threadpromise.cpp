/*
是否熟悉POSIX多线程编程技术？如熟悉，编写程序完成如下功能：
1）有一int型全局变量g_Flag初始值为0；
2） 在主线称中起动线程1，打印“this is thread1”，并将g_Flag设置为1
3） 在主线称中启动线程2，打印“this is thread2”，并将g_Flag设置为2
4） 线程序1需要在线程2退出后才能退出
5） 主线程在检测到g_Flag从1变为2，或者从2变为1的时候退出

这里采用C++11实现，关于std::future, std::promise实现一次性同步具体请参见我前面的一篇文章：
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
