//
//#include<iostream>  
//#include<thread>  
//#include<mutex>  
//#include<condition_variable>  
//#include<array>  
//#include <boost\circular_buffer.hpp>
//
//using namespace std;
//static mutex myMutex;
//static condition_variable fullCon, emptyCon;
//static boost::circular_buffer<int> myBuffer(10);// 缓冲区大小为10,缓冲区数据为int，这里充当blocking queue  
//
//bool bProducing = true;//一个简陋的设计，当不再生产时采用flag终止消费者线程  
//
//void put(int qty)
//{
//  for ( int i = 0; i < qty; i++ )
//  {
//    unique_lock<mutex> lk(myMutex);
//    while ( myBuffer.full() )
//    {
//      emptyCon.wait(lk);
//    }
//
//   // assert(!myBuffer.full());
//    myBuffer.push_back(i);
//    cout << "Produce @ " << i << endl;//生产  
//    fullCon.notify_all();
//  }
//  bProducing = false;
//}
//
//void take()
//{
//  myMutex.lock ();
//  while ( bProducing )
//  {
//    unique_lock<mutex> lk(myMutex);
//    while ( myBuffer.empty() )
//    {
//      fullCon.wait(lk);
//    }
//
//    if ( bProducing )
//    {
//     //assert(!myBuffer.empty());
//      cout << "Take  # " << myBuffer.front() << endl;//消费  
//      myBuffer.pop_front();
//      emptyCon.notify_all();
//    }
//  }
//}
//
//void threadbuffer()
//{
//  thread one(take);
//  //thread two(take);
//  //thread three(take);
//  //thread put2(put,100);
//  //
//  one.join();
//  //two.join();
//  //three.join();
//  //put2.join();
//
//  return;
//}
//
