

#include <iostream>
#include <vector>
#include <algorithm>

class sortele
{
public:
    int m_n;
    sortele(int n)
    {
        m_n = n;
    }
    bool operator <(const sortele &d1)
    {
        return m_n < d1.m_n;
    }
};

using namespace std;


void quicksortmain()
{
    vector<sortele> v = {3,4,61,1,6};
    std::sort(v.begin(),v.end());

    for(auto i: v)
    {
        cout << i.m_n <<endl;
    }

}