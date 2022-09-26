#include <vector>
#include <iostream>

using namespace std;

int SumMax(vector<int> &v)
{
    int sm = 0;
    int s=0;
    for(auto i: v)
    {
        s+=i;
        if(s < 0)
        {
            s=0;
        }

        if(s > sm)
        {
            sm = s;
        }
    }

    return sm;
}

void NumberSumMaxMain()
{
    vector<int> a={-1,2,4,2,-3,-10,-1,-2,4,5,4,-5,-6};
    cout << SumMax(a) << endl;
}