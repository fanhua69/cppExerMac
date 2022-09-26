
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

//读者  
static void read( int readerID)
{
  while ( 1 )
  {
    {//放在块内可以使临时对象得到及时析构  
      shared_ptr<vector<int>> ptrBook;
      {
        unique_lock<mutex> lk(mutexRW);//这里读者和读者之间，读者和写者之间都互斥，但是临界区很小所以不用担心读者和读者间的互斥  
        ptrBook = g_ptrBook;//这里会使对象的引用计数加1  
        assert(!ptrBook.unique());
      }

      //如果存在写者，那么读者访问的是旧的vector  
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

//写者:
static void write()
{
  while(true)
  {
    //在一个块内使临时对象及时得到析构  
    {
      unique_lock<mutex> lk(mutexRW);//写者和写者之间，写者和读者之间都要互斥  
      if ( !g_ptrBook.unique() )//如果存在其它写者或读者，则需要拷贝当前的vector  
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