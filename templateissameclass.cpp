

template <typename T, typename U>
struct is_same
{
    static const bool value = false;
};

template <class T>
struct is_same<T,T>
{
    static const bool value = true;
};

template<class A,class B>
bool is_same_class()
{
    is_same<A,B>::value;
    is_same<A>::value;
}