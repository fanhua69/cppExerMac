

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void equalrangemain()
{
    vector<int> a = {1,2,3,4,5,5,5,5,5,5,6,7};
    auto p = equal_range(a.begin(),a.end(),5);
    
    for_each(p.first,p.second,[](int a){cout << a << endl;});

}