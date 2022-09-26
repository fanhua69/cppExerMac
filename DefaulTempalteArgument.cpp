

template <class T, class = int>
void foo(T a)
{
 // int m = a;
}

class st
{
public:
  //operator int () = delete;
  double m;
};


void DefaultTemplateArgument()
{
  st a;
  a.m = 10;
  foo<>(a);
}