
#include <vector>
#include <iostream>

using namespace std;

void calculateDistance(vector<string> &a, vector<vector<int>> &dis)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {
            int na = a[i].length();
            int nb = a[j].length();
            int n = na < nb ? na :nb;
            int sn = 0;
            for(int k=1;k<n;k++)
            {
                if(a[i].substr(na-k) ==a[j].substr(0,k))
                {
                    sn = k;
                    break;
                }
            }

            dis[i][j] = nb - sn;
        }
    }
}

string findSmallestDP(vector<string> &a, vector<vector<int>> &dis)
{
    //vector<int> path;
    //vector<int> len;
    //for(int i=0;i<a.size();i++)
    //{
    //    path.push_back(i);
    //    len = 0;
    //    for(int j=0;j<a.size();j++)
    //    {
    //        path.push_back(j);
    //        len += dis[i][j];
    //    }
    //}
    return string();
}


void findSmallestSuperStringDPMain()
{
    vector<string> a = { "catg","ctaagt","gcta","ttca","atgcatc" };
    string ans = "gctaagttcatgcatc";

    //vector<string> a = { "a","b","c","d","e" };

    int N = a.size();
    vector<vector<int>> dis (N,vector<int>(N,0));
    calculateDistance(a,dis);

    string s ;
    //s = findSmallestDP(a);
    //cout << s << endl;
    //cout << ans << endl;
    //cout << (s == ans) << endl;
}