
#include<iostream>  
#include<functional>  
#include<thread>  
#include<future>  
#include<utility>  
#include<stdio.h>  
#include<chrono>  
#include<atomic>  

//#include<pthread.h>  

using namespace std;
atomic<int> flag(0);//����ԭ�Ӳ�������g_Flag�Ķ�д  

void worker1(future<int> fut)
{//�߳�1  
  printf("this is thread1\n");
  flag = 1;
  fut.get();//�߳�1�������߳�2���ù���״̬  
  printf("thread1 exit\n");
}

void worker2(promise<int> prom)
{//�߳�2  
  printf("this is thread2\n");//C++11���߳����coutû��boost�ĺã����ǻ�����������Բ���printf���е㲻ˬ  
  flag = 2;
  prom.set_value(10);//�߳�2�����˹���״̬���߳�1�Żᱻ����  
  printf("thread2 exit\n");
}

void threadfuture()
{
  promise<int> prom;
  future<int> fut = prom.get_future();
  thread one(worker1, move(fut));//ע��future��promise�������������Ǿ߱�move����  
  thread two(worker2, move(prom));
  while ( flag.load() == 0 );
  one.detach();
  two.detach();
  //pthread_exit(NULL);//���̵߳������˳�  

  printf("main thread exit\n");
  return;
}