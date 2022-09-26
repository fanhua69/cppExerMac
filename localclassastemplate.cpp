
template <class T>
class A
{
};

template <class T>
class B
{
    typedef A < B <T> > bbb;
};

template <class T>
void foo(T a)
{
    class C
    {
        typedef A<C> b; // error before c++11
    };
}
