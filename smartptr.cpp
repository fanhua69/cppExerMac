
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
      cout << "����" << rp->count << "��ָ��ָ���������" << endl;
  }

private:
  U_Ptr *rp;
};


int smartptrmain()
{
  //����һ������������ָ��
  double *pa = new double(10);

  //������������ָ������󣬶���ָ����������pa
  //ʹ�û����ſ�������ָ��ָ��������ڣ��۲�����ı仯

  {
    SmartPtr sptr1(pa);//��ʱ����count=1
    {
      SmartPtr sptr2(sptr1); //���ø��ƹ��캯������ʱ����Ϊcount=2
      {
        SmartPtr sptr3 = sptr2; //���ø�ֵ����������ʱ����Ϊconut=3
        SmartPtr sptr4 = sptr3; //���ø�ֵ����������ʱ����Ϊconut=3
      }
      //��ʱcount=2
    }
    //��ʱcount=1��
  }
  //��ʱcount=0��pa����delete��

  cout << *pa << endl;
  return 0;
}