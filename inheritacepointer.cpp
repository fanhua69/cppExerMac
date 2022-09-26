

#include <iostream>
using namespace std;
namespace deriA
{
    class ABase
    {
        virtual void method()
        {
            std::cout << "from Base" << std::endl;
        }
    public:
        virtual ~ABase()
        {
            cout <<"Base des" <<endl;
            method();
        }

        void baseMethod()
        {
            cout << "Base method" << endl;
            method();
        }
    };

    class ADer : public ABase
    {
        void method()
        {
            cout << "A method " << endl;
            std::cout << "from A" << std::endl;
        }

    public:
        ~ADer()
        {
            cout << "A des" << endl;
            method();
        }
    };
}


using namespace deriA;

int inheritancepointer(void)
{
    ABase* base = new ADer;
    base->baseMethod();
    delete base;
    return 0;
}