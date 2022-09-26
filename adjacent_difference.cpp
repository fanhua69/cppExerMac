

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

template<class T>
void printV(T a)
{
    cout << a << endl;
}

void adjacent_differenceMain()
{
    vector<int> a= {5,4,3,2,1};
    vector<int> b = {1,2,3,4,5} ;

    std::adjacent_difference(a.begin(),a.end(),b.begin());

    for_each(b.begin(),b.end(),printV<int>);
}