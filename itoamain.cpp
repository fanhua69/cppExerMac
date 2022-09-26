

#include <numeric>
#include <iostream>
#include <list>
#include <functional>

using namespace std;
using namespace std::placeholders;


void iotamain()
{
    list<int> a = {1,2,4,5,6,7,8};
    a.resize(20);
    for ( auto i : a )
    {
        cout << i << endl;
    }

    std::iota(a.begin(),a.end(),0);

    for(auto i: a)
    {
        cout << i << endl;
    }
}

