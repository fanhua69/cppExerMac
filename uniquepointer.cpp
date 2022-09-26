#include <iostream>
#include <cstdlib>
#include <memory>

using namespace std;

struct Foo
{
    Foo(int mm, int nn)
    {
        m = mm;
        n = nn;
    }

    Foo()
    {
        cerr << "Foo [" << this << "] constructed\n";
    }
    virtual ~Foo()
    {
        cerr << "Foo [" << this << "] destructed\n";
    }

    int m;
    int n;
};


void testUniquePointer(std::unique_ptr<Foo> p)
{
    p->m = 11;
    p->n = 12;
}

std::unique_ptr<Foo> testUP()
{
    std::unique_ptr<Foo> p = make_unique <Foo>(1,2);
    return p;
}

int uniquepointer()
{
    {
        unique_ptr<Foo> fp(new Foo());

        // unique_ptr<Foo> fp2(fp);    // ERROR! can't copy unique_ptr
        unique_ptr<Foo> fp3;
        //fp3 = fp;                   // ERROR! can't assign unique_ptr

        cerr << "Exiting scope\n";
    } // fp will be destroyed, and will destruct the pointed object


   unique_ptr<Foo> p = make_unique<Foo>(11,22);

    //testUniquePointer(p);

    return 0;
}