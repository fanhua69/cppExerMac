

#include <iostream>
#include <vector>

using namespace std;

vector<int> findLongestSubSequence(const vector<int> &data)
{
    vector<vector <int> >LSS(data.size());

    LSS[0].push_back(data[0]);

    for(unsigned int i=1;i<data.size();++i)
    {
        int n = -1;
        unsigned int s = 0;
        for(unsigned int j=0;j<i;++j)
        {
            if(data[j] < data[i] && LSS[j].size() > s)
            {
                n = j;
                s = LSS[j].size();
            }
        }

        if(n != -1)
        {
            LSS[i] = LSS[n];
        }
        LSS[i].push_back(data[i]);
    }    

    int longestLSS = 0;
    for(unsigned int i = 0; i<LSS.size();++i)
    {
        if(LSS[i].size() > longestLSS)
        {
            longestLSS = i;
        }
    }

    for(auto v : LSS)
    {
        for(auto d : v)
        {
            cout << d << " ";
        }
        cout << endl;
    }
    
    return LSS[longestLSS];
}

void findLongestSubSequenceMain()
{
    vector<int> data={3,2,6,4,5,1};
    vector<int> LSS = findLongestSubSequence(data);

    for(int i: LSS)
    {
        cout << i << endl;
    }


}
