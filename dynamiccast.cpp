
#include <iostream>


using namespace std;


//We cannot touch base class A but can be inherited. 
namespace dynamiccast
{
    class A
    {
    public:
        virtual void func()
        {
            printf("Class A :func()\n");
        }
        void func2()
        {
            printf("Class A :func2()\n");
        }//Not virtual 
    };


    class B : public A
    {
    public:
        void func()
        {
            printf("Class B :func()\n");
        }

        void func2()
        {
            printf("Class B :func2()\n");
        }
    };

    class C : public A
    {
    public:
        void func()
        {
            printf("Class C :func()\n");
        }
    };


    //-----Client code------
    void f(A* arg)
    {

        //call 
        C* bp = dynamic_cast<C*>(arg);

        //Call Specific class B function.
        if ( bp )
        {
            bp->func();
            bp->func2();
        }
        else
        {
            //Call respective class function
            arg->func();
        }
    };
}


int dynamiccastmain()
{
    using namespace dynamiccast;

    A* ap1 = new B();
    f(ap1);


    //operate C object
    A* ap2 = new C();
    f(ap2);

    return 0;
}
