
#include <iostream>

using namespace std;

class U_Ptr
{
private:

  friend class SmartPtr;
  
  U_Ptr(void *ptr) :p(ptr), count(1)
  {
  }

  ~U_Ptr()
  {
    delete p;
  }

  int count;
  void *p;
};

class SmartPtr
{
public:
  SmartPtr(void *ptr) :rp(new U_Ptr(ptr))
  {
  }

  SmartPtr(const SmartPtr &o) :rp(o.rp)
  {
    ++rp->count;
  }

  SmartPtr& operator=(const SmartPtr& o)
  {
    ++o.rp->count;
    if ( --rp->count == 0 )
      delete rp;
    rp = o.rp;
    return *this;
  }

  ~SmartPtr()
  {
    if ( --rp->count == 0 )
      delete rp;
    else
      cout << "还有" << rp->count << "个指针指向基础对象" << endl;
  }

private:
  U_Ptr *rp;
};


int smartptrmain()
{
  //定义一个基础对象类指针
  double *pa = new double(10);

  //定义三个智能指针类对象，对象都指向基础类对象pa
  //使用花括号控制三个指针指针的生命期，观察计数的变化

  {
    SmartPtr sptr1(pa);//此时计数count=1
    {
      SmartPtr sptr2(sptr1); //调用复制构造函数，此时计数为count=2
      {
        SmartPtr sptr3 = sptr2; //调用赋值操作符，此时计数为conut=3
        SmartPtr sptr4 = sptr3; //调用赋值操作符，此时计数为conut=3
      }
      //此时count=2
    }
    //此时count=1；
  }
  //此时count=0；pa对象被delete掉

  cout << *pa << endl;
  return 0;
}