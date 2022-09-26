
#include <memory>
#include <iostream>

using namespace std;

class TestPF
{
  int * arr { nullptr };
public:
  TestPF() :arr(new int[500] { 1,2,3,4 })
  {
    cout << "default constructor" << endl;
  }
  TestPF(const TestPF & t)
  {
    cout << "copy constructor" << endl;
    if ( arr == nullptr ) arr = new int[500];
    memcpy(arr, t.arr, 500 * sizeof(int));
  }
  TestPF(TestPF && t) : arr(t.arr)
  {
    cout << "move constructor" << endl;
    t.arr = nullptr;
  }
  ~TestPF()
  {
    cout << "destructor" << endl;
    delete[] arr;
  }
};

template <typename T>
void func(T t)
{
  cout << "in func rv" << endl;
}

template <typename T>
void relay(T&& t)
{
  cout << "in relay" << endl;
  func(std::forward<T>(t));
}


static void foo(TestPF &f)
{
  TestPF ff = std::move(f);
}

static void foo(TestPF &&f)
{
  TestPF ff = std::move(f);
}

void perfectforwarding1()
{
  TestPF t;
  foo(t);
  foo(TestPF());

  relay(t);
}