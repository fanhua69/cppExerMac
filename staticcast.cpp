
#include <cstdlib>
#include <iostream>

using namespace std;


class StaticCastBase
{
    int i;
public:
    StaticCastBase()
    {
        std::cout << "Base Constructor" << endl;
    }

    StaticCastBase(const StaticCastBase &)
    {
        std::cout << "Base Copy Constructor" << endl;
    }
    virtual ~StaticCastBase()
    {
        std::cout << "Base Destructor" << endl;
    }
    virtual void print()
    {
        std::cout << "Its Base printing" << endl;
    }
    virtual void print_s()
    {
        std::cout << "Its Base print_2" << endl;
    }
};

class StaticCastDerived : public StaticCastBase
{
public:
    StaticCastDerived()
    {
        mmm =3;
        std::cout << "Derived Constructor" << endl;
    }
    StaticCastDerived(const StaticCastDerived &)
    {
        std::cout << "Derived Copy Constructor" << endl;
    }
    virtual ~StaticCastDerived()
    {
        std::cout << "Derived Destructor" << endl;
    }
    void print()
    {
        std::cout << "Its Derived printing" << endl;
    }
    void print_s()
    {
        std::cout << "Its Derived print_2" << endl;
    }

    int mmm;
};

int staticcast()
{
    StaticCastDerived* b = new StaticCastDerived();
    StaticCastBase *pp = dynamic_cast<StaticCastBase*>(b);
    pp->print();

    //delete b;

    return 0;
}