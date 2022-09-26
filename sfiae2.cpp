template <int I > 
struct A
{
};

char xxx(int)
{
  return 'a';
};

char xxx(float)
{
  return 'b';
};

template <class T> 
A<sizeof(xxx((T)0))> f(T)
{
  return A<1>();
};

void sfiae()
{
  f(1);
}


