

#include <string>

#include <iostream>
#include <iomanip>

using namespace std;

void stdstring()
{
    
    string a = "abcdedghijklmn";
    string b = "de";
    string c =  "op";
    string::size_type s = a.find(b);
    int pos=s;
    a.substr(0,pos);

    double ddd = 13.1415926;

    cout << setprecision(3) << ddd << "ABC" << endl;
    cout << setw(3) << ddd << "ABC" << endl;
    int n = string::npos;
    cout << n << endl;
    if(s != string::npos)
    {
        cout << s << endl;
        cout << a[s];
    }
}