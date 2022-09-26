
#include <mutex>
#include <thread>
#include <iostream>
#include <future>

using namespace std;

int countdown(int from, int to)
{
  for ( int i = from; i != to; --i )
  {
    std::cout << i << 'n';
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  std::cout << " Lift off!\n";
  return from - to;
}

void stdpackage()
{
  std::packaged_task<int(int, int)> tsk(countdown);
  std::future<int> ret = tsk.get_future();
  std::thread th(std::move(tsk), 10, 0);
  int value = ret.get();
  std::cout << "The countdown lasted for " << value << " seconds.n";
  th.join();
}