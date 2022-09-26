

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

bool findPath(string s, string e, set<string> &d,  vector<string> &path)
{
    if(s==e)
    {
        return true;
    }

    for(int i=0;i<s.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            string s1=s;
            s1[i] = 'a'+j;
            if(s1!=s && d.find(s1)!=d.end() && find(path.begin(),path.end(),s1)==path.end())
            {
                path.push_back(s);
                if(findPath(s1,e,d,path))
                {
                    return true;
                }
                path.pop_back();
            }
        }
    }

    return false;
}

vector<pair<string,vector<string>>> expand(string s,set<string> &d,vector<string> &path)
{
    vector<pair<string,vector<string>>> v;
    for(int i=0;i<s.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            string s1 = s;
            s1[i] = 'a'+j;
            if(d.find(s1)!=d.end() && std::find(path.begin(), path.end(),s1) == path.end())
            {
                vector<string> np = path;
                np.push_back(s1);
                v.push_back({s1,np});
            }
        }
    }

    return v;
}

vector<string> findPathBFS(string s, string e, set<string>&d)
{
    queue<pair<string,vector<string>>> q;

    vector<string>path;
    path.push_back(s);

    q.push({s,path});

    int steps = 0;
    while(!q.empty())
    {
        int s = q.size();
        while(s--)
        {
            auto n = q.front();
            q.pop();

            vector<pair<string,vector<string>>> v = expand(n.first,d,n.second);
            for(auto i: v)
            {
                if(i.first == e)
                {
                    return i.second;
                }
                q.push(i);
            }
        }
        steps++;
    }

    return path;
}

void letterLadderMain()
{
    string s = "hit";
    string e = "cog";
    std::set<string> m={"hot","dot","dog","lot","log","cog"};

    vector<string> path;
    if(findPath(s,e,m,path))
    {
        for(auto i:path)
        {
            cout << i << endl;
        }
    }

    vector<string>  p = findPathBFS(s, e, m);
    for(auto i:p)
    {
        cout << i << endl;
    }

}