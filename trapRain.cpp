
#include <vector>
#include <iostream>

using namespace std;

int trapRain(vector<int> &t)
{
    if(t.empty())
    {
        return 0;
    }

    int N = t.size();
    vector<int> leftMax(N),rightMax(N);
    
    int m = 0;
    for(int i=0;i<N;i++)
    {
        if(t[i]>m)
        {
            m = t[i];
        }
        leftMax[i] = m;
    }

    m=0;
    for(int i=N-1;i>=0;i--)
    {
        if(t[i]>m)
        {
            m = t[i];
        }
        rightMax[i] =  m;
    }

    int sum = 0;
    for(int i=1;i<N-1;i++)
    {
        sum+=leftMax[i]<rightMax[i]? leftMax[i] - t[i] : rightMax[i] -t[i];
    }

    return sum;
}

void trapRainMain()
{
    vector<int> t = {0,1,0,2,1,0,1,3,2,1,2,1};
    // out put is 6:

    int s = trapRain(t);

    cout << s << endl;
}