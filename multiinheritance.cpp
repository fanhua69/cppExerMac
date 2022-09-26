class A
{
public:
  virtual void func(int)
  {
  }

  virtual void func(double,double)
  {
  
  }
};

class B: public A
{
public:
 void func(float,float,float)
 {
 };
};

int multiinheritance()
{
  B b;
  b.func (1,1,1);
  return 0;
}