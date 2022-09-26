
#include <vector>
#include <string>
#include <iostream>


using namespace std;

string longestCommonPrefix(vector<string>&strs)
{
    if(strs.size()<1)
    {
        return string("");
    }

    for(int i=0;i<strs[0].size();i++)
    {
        char c = strs[0][i];
        for(int j=1;j<strs.size();j++)
        {
            if(i>=strs[j].size() || strs[j][i] != c)
            {
                return strs[0].substr(0, i);
            }
        }
    }

    return strs[0];
}

string longestCommonPrefix2(vector<string>&strs)
{
    if(strs.size() == 0)
    {
        return string("");
    }

    string prefix = strs[0];

    for(int i=1;i<strs.size();i++)
    {
        while(strs[i].find(prefix)!=0)
        {
            prefix = prefix.substr(0,prefix.size()-1);
            if(prefix.empty())return "";
        }
    }

    return prefix;
}

void longestCommonPrefixMain()
{
    vector<string> strs={"flight","flower","flow"};
    cout << longestCommonPrefix2(strs) << endl;
}