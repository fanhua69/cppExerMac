


#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool lexicom(int a, int b)
{
    return a > b;
}

void lexicographical_comparemain()
{
    vector<int> a = { 1,2,4,4,5};
    vector<int> b = { 1,2,3,4,5};

    bool c = std::lexicographical_compare(a.begin(),a.end(),b.begin(),b.end(),lexicom);

}