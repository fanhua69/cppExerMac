
#include <iostream>  // NOLINT
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <winsock.h>
#include <time.h>    

int countn = 10000000;

using namespace std;


__declspec(thread)int tls_i = 10;
int *ppp = &tls_i;       //This will generate an error in C.  

void threadmain(void)
{
  static __declspec(thread)int tls_i; // define thread local variable
  static char __declspec(thread) *ch;

  int nnn = *ppp;

  unsigned int nProcessorQty = thread::hardware_concurrency(); // 获取物理线程数目
  int i = 0;
  thread* ta = new thread([]()
  {
    int t1 = 1;
    for ( int i = 0, m = 13; i < countn; i++, m *= 17 )
    {
      this_thread::yield();
    }
    int t2 = 122;
    cout << t1 << " " << t2 << endl;
  });

  thread** tb = new thread*[nProcessorQty];
  for ( i = 0; i < nProcessorQty; i++ )
  {
    tb[i] = new thread([]()
    {
      int t1 = 1;
      for ( int i = 0, m = 13; i < countn; i++, m *= 17 )
      {
        int n = 123;
      }
      int t2 = 134;
      cout << t1 << " " << t2 << endl;
    });
  }
  ta->join();
  delete ta;
  for ( i = 0; i < nProcessorQty; i++ )
  {
    tb[i]->join();
    delete tb[i];
  };
  delete tb;
}