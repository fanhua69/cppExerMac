

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

void stdstringstream()
{
    std::stringstream s;
    s << "124.4 " <<  " 234" << endl;

    double a;
    int b,c;
    s >> a >> b >> c;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}