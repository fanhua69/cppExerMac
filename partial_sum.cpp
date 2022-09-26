

#include <numeric>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template < class T>
T f111(T a, T b, T c)
{
    return a+b+c;
}


void partial_sumMain()
{
    using namespace std::placeholders;

    vector<int> a = {1,2,3,4,5};
    vector<int> b = {1,1,1,1,1};

    auto f1 = std::bind(f111<int>, _1, _2,11);

    partial_sum(a.begin(),a.end(),b.begin(),bind(f111<int>,_1,_2,11));

    for(auto i: b)
    {
        cout << i << endl;
    }
}
