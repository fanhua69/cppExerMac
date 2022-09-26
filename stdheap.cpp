#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void stdheapmain()
{
    vector<int> v = {1,2,3,4};

    std::make_heap(v.begin(),v.end());
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    std::push_heap(v.begin(),v.end());

    auto e = v.end();
    while(true)
    {
        cout << v.front() << endl;
        pop_heap(v.begin(),e);
        e--;
        if(e==v.begin())
        {
            break;
        }
    }
}