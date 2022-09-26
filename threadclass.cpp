

#include <thread>
#include <iostream>
#include <mutex>
#include <future>

using namespace std;

mutex mymutext;

class threadclass
{
public:
  threadclass(int &j):mm(j)
  {
  };

  int &mm;

  int operator ()(int n)
  {
    std::lock_guard<mutex> lk(mymutext,std::adopt_lock);
    cout << "class thread " << n << endl;
    return 98;
  }

  void operator ()(int n,string s)
  {
    std::unique_lock<mutex> lk(mymutext);
    cout << "class thread " << n << s.c_str () << endl;
  }

  void fun()
  {
    mm = mm*2;
  }

};

void threadclassmain()
{
  int m= 9;
  threadclass c(m);
  std::thread t(c,1);
  std::thread t7;
  t7 = std::move(t);
  
  t7.join();
}