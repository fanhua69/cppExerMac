

#include<iostream>  
#include<thread>  
#include<mutex>  
#include<condition_variable>  

using namespace std;
mutex gmutex;

condition_variable gCondition;
int bProducing = 10;

void fun(int num)
{
  for ( int i = 0; i < 50; i++ )
  {
    // A unique lock is an object that manages a mutex object 
    // with unique ownership in both states: locked and unlocked.  
    unique_lock<mutex> lk(gmutex);
    
    while ( bProducing != num )
    {
      gCondition.wait(lk);//在调用wait时会执行lk.unlock()  
    }

    for ( int j = 0; j < num; j++ )
    {
      cout << j << " ";
    }

    cout << endl;


    bProducing = (num == 10) ? 100 : 10;
    gCondition.notify_one();//被阻塞的线程唤醒后lk.lock()恢复在调用wait前的状态  
  }
}

void threadreadwrite()
{
  thread child(fun, 10);
  fun(100);
  child.join();
  return;
}
