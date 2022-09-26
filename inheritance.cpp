

class base;

class base
{
friend class f;

public:
  base()
  {
  };
  base(int){};
  ~base(){};

  static void ff(){};

private:

  int m;
};

class derived: public base
{
public:
  derived(){};
  ~derived()
  {
    int m = 0;
  };

private:
  int  m_d;
};

class f
{
public:
  f()
  {
    base b;
    b.m = 10;

    derived d;
    d.m = 10;
  }
};

void inheritance()
{
  derived a;
  a.~derived();
  a.ff();
}