

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void adjacentfindmain()
{
    vector<int> a = {1,2,3,4,5,6,7,8,8,9};
    auto i = adjacent_find(a.begin(),a.end());
    if(i!=a.end())
    {
        cout << *i << endl;
        cout << *(i+1) << endl;
    }

    vector <int> b = { 1,2,8,4,5,6};
    pair<vector<int>::iterator, vector<int>::iterator> i1 = mismatch(a.begin(),a.end(),b.begin(),b.end());
    
    if(i1.first!=a.end() && i1.second != b.end())
    {
        cout << *(i1.first) << endl;
        cout << *(i1.second)<< endl;

    }


}