

#include <thread>
#include <atomic>
#include <iostream>

using namespace std;

static std::atomic_flag lock = ATOMIC_FLAG_INIT;
static void f(int n)
{
  while ( lock.test_and_set(std::memory_order_acquire) ) //≥¢ ‘ªÒµ√À¯
  {
    cout << "waiting from thread ." << n << endl; // ◊‘–˝
  }

  cout << "Thread 11 << n << 11 starts working" << endl;
}

static void g(int n)
{
  cout << "Thread  "<< n << " is going to start." << endl;
  lock.clear();
  cout << "Thread " << n << " starts working" << endl;
}

int threadtestandset()
{
  lock.test_and_set();
  std::thread t1(f, 1);
  std::thread t2(g, 2);
  t1.join();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  t2.join();
  return 0;
}