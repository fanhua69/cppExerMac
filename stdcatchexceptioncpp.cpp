


#include <iostream>
#include <string>
#include <exception>

using namespace std;

void stdcatchexception()
{
    try
    {
        throw(new exception("no memoty asd", 123));
        throw(string("sss"));
    }
    catch (exception* e)
    {
        cout << e->what() << endl;
        delete e;
    }
    catch ( exception e )
    {
        cout << e.what() << endl;
    }
    catch(string s)
    {
        cout << s << endl;
    }
    catch(...)
    {
    
    }
}