
#include <iostream>
#include <functional>
using namespace std;

class CMyFHView
{
public:
  void onClick(int x, int y)
  {
    cout << "X : " << x << ", Y : " << y << endl;
  }

  int tryFunction(int x, int y,int z)
  {
    cout << "X2 : " << x << ", Y2 : " << y << "Z:"<< z << endl;
    return 0;
  }

};

// 定义function类型, 三个参数
std::function<void(CMyFHView, int, int)> clickCallback;
std::function <bool (CMyFHView, int,int,int)> tryF;

int stdfunction()
{
  CMyFHView button;

  // 指向成员函数
  clickCallback = &CMyFHView::onClick;
  tryF = &CMyFHView::tryFunction;

  // 进行调用
  clickCallback(button, 10, 123);
  bool b=tryF(button,10,20,30);

  return 0;
}