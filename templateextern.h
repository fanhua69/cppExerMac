

template <class T>
class MyClass
{
public:
  void swap(T &a, T &b)
  {
    a = a ^b;
    b  = b^a;
    a = a^b;
  }
};