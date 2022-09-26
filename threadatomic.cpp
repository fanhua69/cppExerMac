

#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>


using namespace std;

static std::atomic<int> atomic_int_a = 0;
static std::atomic<int> atomic_int_n = 0;
static std::mutex              gMutex;
static std::condition_variable gCondition;

void setValue()
{
  while(true)
  {
    std::unique_lock<mutex> lock(gMutex);
    gCondition.wait(lock,[](){return atomic_int_a == 0;});

    atomic_int_n++;
    atomic_int_a.store(atomic_int_n,memory_order_relaxed);
    cout << "Setting:" << atomic_int_n << endl;
    gCondition.notify_all();
   // std::atomic_thread_fence (memory_order_seq_cst);
  }
}


void showValue()
{
  while(true)
  {
    std::unique_lock<mutex> lock(gMutex);
    gCondition.wait(lock,[](){return atomic_int_a!=0;});

    atomic_int_a.load();
    cout << "Showing:" << atomic_int_a << endl;
    atomic_int_a.store(0);
    gCondition.notify_all();
  }
}

void threadatomic()
{
  std::thread a(setValue);
  std::thread b(showValue);

  a.join ();
  b.join();

}