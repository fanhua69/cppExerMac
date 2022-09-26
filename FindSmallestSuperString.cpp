

#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

std::map <string,string> mids;
int FOUND = 0;
int NOTF=0;

string link2Words(string &a, string &b)
{
    int na = a.size();
    int nb = b.size();
    int nm = na < nb ? na : nb ;

    int lp = 0;
    for ( int i = nm; i > 0; i--)
    {
        if ( a.substr(na - i, i) == b.substr(0, i) )
        {
            lp = i;
            break;
        }
    }

    return a.substr(0, na-lp) + b;
}

string findSmallestSuperString(string &a, string &b)
{
    string s ;
    string key = a + b;
    auto it = mids.find(key);
    if(it!=mids.end())
    {
        FOUND ++;
        cout << "Found:" << FOUND << endl;
        return it->second;
    }
    NOTF++;
    cout << "Not found" << NOTF <<endl;

    if(a.find(b)!=-1)
    {
        s = a;
    }
    else if(b.find(a)!=-1)
    {
        s = b;
    }
    else
    {
        s = link2Words(a,b);
    }

    mids[key]=s;

    return s;
}

string findSmallestSuperString(vector<string> &a, int l, int r)
{
    if(l==r)
    {
        return a[l];
    }
    else if(l+1 == r )
    {
        return findSmallestSuperString(a[l],a[r]);
    }

    int m = (l+r)/2;
    string s1 = findSmallestSuperString(a, l,m);
    string s2 = findSmallestSuperString(a, m+1, r);

    return findSmallestSuperString(s1,s2);
}

void findSmallestSuperStringPermutations(vector<string> &a, int i,vector<string> &sm)
{
    int N = a.size();

    if ( i == N - 1 )
    {
        for(auto s : a)
        {
            cout << s << " " ;
        }
        cout << endl;

        sm.push_back(findSmallestSuperString(a, 0,a.size()-1));
        return;
    }

    for(int j= i;j<N;j++)
    {
        if(i!=j)
        {
            swap(a[i],a[j]);
        }

        findSmallestSuperStringPermutations(a, i+1, sm);

        if ( i != j )
        {
            swap(a[i], a[j]);
        }
    }
}

string findSmallest(vector<string> &a)
{
    if(a.size()<1)
    {
        return string("");
    }

    vector<string> sm;
    findSmallestSuperStringPermutations(a, 0, sm);

    string ss = sm[0];
    for ( auto s : sm)
    {
        if ( s.size()<ss.size() )
        {
            ss = s;
        }
    }

    return ss;
}

void findSmallestSuperStringMain()
{
    vector<string> a = {"catg","ctaagt","gcta","ttca","atgcatc"};
    string ans = "gctaagttcatgcatc";

    //vector<string> a = { "a","b","c","d","e" };
    string s = findSmallest(a);
    cout <<  s << endl;
    cout << ans << endl;
    cout <<(s==ans) << endl;
}