

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
void print_square(T i)
{
    cout << i*i  << endl;
}


void foreach2()
{
    vector<int> v ={1,2,3,4,5};
    // vector gets filled
    for_each(v.begin(), v.end(), print_square<int>);

    return;
}