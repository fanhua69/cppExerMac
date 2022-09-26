

#include <iostream>

class A
{
public:
    A()
    {
    }
    ~A()
    {
        //throw 42;
    }
};

void throwexception()
{
    try
    {
        A a;
        throw 32;
    }
    catch ( int a )
    {
        std::cout << a;
    }
}