

#include <thread>
#include <atomic>
#include <iostream>
//#include <unistd.h>

std::atomic_flag lockatomic_flag = ATOMIC_FLAG_INIT;

using namespace std;

void f(int n)
{
  while(lockatomic_flag.test_and_set(std::memory_order_acquire))
  {
    cout << "Waiting from thread " << n << endl;
  }

  cout << "Thread starts working.." << n << endl;
}

void g(int n)
{
  cout << "Thread " << n << " is going to start. " << endl;
  lockatomic_flag.clear ();  //Clears the atomic_flag (i.e., sets it to false).
  cout << "Thread " << n << " starts working . " << endl;
}

void thread_atomic_flag()
{
  lockatomic_flag.test_and_set ();  // set the flag to true;

  thread t1(f,1);
  std::chrono::milliseconds timespan(4000); // or whatever
  std::this_thread::sleep_for(timespan);

  thread t2(g, 2);
  t1.join();
  t2.join();
}




