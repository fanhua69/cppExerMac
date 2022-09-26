

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
      gCondition.wait(lk);//�ڵ���waitʱ��ִ��lk.unlock()  
    }

    for ( int j = 0; j < num; j++ )
    {
      cout << j << " ";
    }

    cout << endl;


    bProducing = (num == 10) ? 100 : 10;
    gCondition.notify_one();//���������̻߳��Ѻ�lk.lock()�ָ��ڵ���waitǰ��״̬  
  }
}

void threadreadwrite()
{
  thread child(fun, 10);
  fun(100);
  child.join();
  return;
}
