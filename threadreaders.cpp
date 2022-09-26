
#include<iostream>  
#include<mutex>  
#include<thread>  
#include<memory>  
#include<vector>  
#include<assert.h>  

using namespace std;
static mutex mutexRW;
static mutex mutexCout;
static std::condition_variable con_out;
static shared_ptr<vector<int>> g_ptrBook;
static int g_readerTurn = 1;
static int g_bookOrder = 0;

//����  
static void read( int readerID)
{
  while ( 1 )
  {
    {//���ڿ��ڿ���ʹ��ʱ����õ���ʱ����  
      shared_ptr<vector<int>> ptrBook;
      {
        unique_lock<mutex> lk(mutexRW);//������ߺͶ���֮�䣬���ߺ�д��֮�䶼���⣬�����ٽ�����С���Բ��õ��Ķ��ߺͶ��߼�Ļ���  
        ptrBook = g_ptrBook;//�����ʹ��������ü�����1  
        assert(!ptrBook.unique());
      }

      //�������д�ߣ���ô���߷��ʵ��Ǿɵ�vector  
      std::unique_lock<mutex> lkOut(mutexCout);
      while(g_readerTurn != readerID)
      {
        con_out.wait (lkOut);
      }
      cout << readerID << " Reading : ";
      for ( auto it = ptrBook->begin(); it != ptrBook->end(); it++ )
      {
        cout << *it << "," ;
      }
      cout << endl;
      g_readerTurn ++ ;
      if( g_readerTurn > 2)
      {
        g_readerTurn = 1;
      }
      con_out.notify_all ();
    }
  }
}

//д��:
static void write()
{
  while(true)
  {
    //��һ������ʹ��ʱ����ʱ�õ�����  
    {
      unique_lock<mutex> lk(mutexRW);//д�ߺ�д��֮�䣬д�ߺͶ���֮�䶼Ҫ����  
      if ( !g_ptrBook.unique() )//�����������д�߻���ߣ�����Ҫ������ǰ��vector  
      {
        g_ptrBook.reset(new vector<int>(*g_ptrBook));
        cout << "New book " << endl;
        g_ptrBook->push_back (g_bookOrder * 10000);
        g_bookOrder++;
      }

      assert(g_ptrBook.unique());

      std::unique_lock<mutex> lkOut(mutexCout);
      int nstart = g_ptrBook->back ();
      for(int i= 0;i<1;i++)
      {
        cout << "Writing:"<< nstart+ i<< endl;
        g_ptrBook->push_back(nstart + i);
      }
    }
  }
}

void threadreaders()
{
  g_ptrBook.reset(new vector<int>);
  thread one(read, 1);
  thread two(read, 2);
  thread t(write);
  one.join();
  two.join();
  t.join();
  return ;
}