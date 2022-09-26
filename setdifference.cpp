

#include <algorithm>
#include <vector>
#include <set>
#include <iterator>

#include <iostream>

using namespace std;

void setdifferencemain()
{
    set<int> a = {1,2,3,4,5,8,9,10};
    set<int> b = {1,2,3,4,6,7};
    set<int> c;

    std::insert_iterator<std::set<int>> it = std::inserter(c,c.begin());
    std::set_difference (a.begin(),a.end(),b.begin(),b.end(),it);

    for(int i : c)
    {
        cout << i << endl;
    }
}