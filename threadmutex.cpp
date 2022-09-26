
#include <iostream>

using namespace std;

#include <mutex>

std::mutex m;

class myclass
{
public:
  int m;
  int n;
};

myclass data1;

void processdata(myclass &d)
{
  d.m += 1;
  d.n += 2;
}

void threadmutex()
{
  std::lock_guard<std::mutex> lk(m);
  processdata(data1);
}