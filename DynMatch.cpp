#include <vector>
#include <iostream>
#include <string>

using namespace std;

enum DynMatching
{
    NotSet,
    NotMatch,
    Matching
};

vector<vector<DynMatching>> dm;

bool DynMatch(int i, int j, string s, string p)
{
    if(i >= s.size() && j >= p.size())
    {
        return true;
    }

    if(dm[i][j] != DynMatching::NotSet)
    {
        return dm[i][j] == NotMatch ? false : true;
    }

    bool firstMatch = ( s[i] == p[j] || p[j] == '.');

    bool answer = false;

    if(j+1<p.size() && p[j+1]=='*')
    {
        answer = firstMatch && DynMatch(i+1,j,s,p) || DynMatch(i, j + 2, s, p);
    }
    else 
    {
        answer = firstMatch && DynMatch(i+1,j+1,s,p);
    }

    dm[i][j] = answer ? NotMatch : Matching;

    return answer;
}

bool isMatch4(string s, string p)
{
    dm.resize(s.length()+1,vector<DynMatching>(p.length() + 1, DynMatching::NotSet));
    return DynMatch(0, 0, s, p);
}