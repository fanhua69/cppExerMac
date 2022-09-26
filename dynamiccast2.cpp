
#include <iostream>

using namespace std;

class dcbase
{
    virtual void a()
    {
    };
};

class dcderived: public dcbase
{
};

class norelation
{};

void dynamiccast2()
{
    dcbase p;
    try
    {
        dcderived &p2 = dynamic_cast<dcderived&>(p);
    }
    catch(string s)
    {
    }
    catch(std::bad_cast e)
    {
        cout << e.what() << endl;
    }

}