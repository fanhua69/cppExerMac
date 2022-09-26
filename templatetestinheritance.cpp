

template<typename D, typename B>
class IsDerivedFromHelper
{
    class No
    {
    };
    class Yes
    {
        int m;
    };

    static Yes Test(B*);
    static No Test(...);

public:

    enum
    {
       Is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes)
    };
};


template <class C, class P>
bool IsDerivedFrom()
{
    return IsDerivedFromHelper<C, P>::Is;
    return true;
}


class A
{

};

class B : public A
{
};

class C// : public B
{
};

void templatetestinheritance()
{
    bool b = IsDerivedFrom<C,A>();
}