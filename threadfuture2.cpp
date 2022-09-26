

#include <iostream>
#include <future>
#include <mutex>

using namespace std;

static void foo(int id, std::future <int> & f)
{
  cout << "before getting state:" <<id << endl;
  int n = f.get ();
  cout << "got state:" << id << endl;
  cout << "state : "<<n<< " " << id <<endl;
}

static void setState(std::promise<int>& p)
{
  cout << "before sleeping" << endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  cout << "waken up" << endl;
  cout << "Going to set state:" <<endl;
  p.set_value (10);
  cout << "set state over." << endl;
}
void threadfuture2()
{
  less<int> functor = less<int>();
  bool bRet = functor(10, 20); // ·µ»Øtrue

  std::promise <int> p;
  std::future<int> &f = p.get_future ();
  std::thread threada(foo,1,std::ref(f));
  std::thread threadb(foo, 2, std::ref(f));
  std::thread thread2(setState,std::ref(p));
  threada.join();
  threadb.join();
  thread2.join();
}