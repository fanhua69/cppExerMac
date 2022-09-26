
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void nthelementmain()
{
    vector<int> a = {1,3,5,3,6,7,9,4,1,2,3,10,11,2,77,-1,-2,4,6,1,2,6,8,9,0,14,111,66};

    nth_element(a.begin(),a.begin()+14, a.end());

    for(auto i: a)
    {
        cout << i <<endl;
    }

}