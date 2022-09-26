

struct A
{
  int m_a;
};
struct B : public A
{
  int m_b;
};

struct C
{
  int m_c;
};

void foo(A &a)
{
  a.m_a = 10;
}
//void foo(B &b)
//{
//  b.m_b = 20;
//}

void substitutionfailure()
{
  foo(A());
  foo(B());
  //foo(C());
}

