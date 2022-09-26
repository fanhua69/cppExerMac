

struct Bar
{
  typedef double internalType;
};

template <typename T>
typename T::internalType foo(const T& t)
{
  //cout << "foo<T>" << endl;
  return 0;
}

void sfinae3()
{
  foo(Bar());
  //foo(0); // << error!
}