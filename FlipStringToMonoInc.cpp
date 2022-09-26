

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int minFlipString(string s)
{
    const int N = s.length();
    vector<int> l(N,0);
    vector<int> r(N+1, 0);

    l[0]=s[0]-'0';
    for(int i=1;i<N;i++)
        l[i]=l[i-1]+s[i]-'0';



    r[N]=0;
    for(int i=N-1;i>=0;--i)
        r[i]=r[i+1]+'1'-s[i];

    int m = r[0];
    for(int i=0;i<N;i++)
        m = min(m,l[i] + r[i+1]);

    return m;
}

int minFlipString2(string s)
{
    const int n=s.size();
    vector<int> l(n+1);
    vector<int> r(n+1);
    l[0]=s[0]-'0';
    r[n-1]='1'-s[n-1];

    for(int i=1;i<n;++i)
        l[i]=l[i-1]+s[i]-'0';

    for(int i=n-2;i>=0;--i)
        r[i]=r[i+1]+'1'-s[i];


    int ans = r[0];
    for(int i=1;i<=n;++i)
    {
        ans = std::min(ans,l[i-1]+r[i]);
    }


    return ans;

}

void flipStringMain()
{
    string s = "0000";
    int n = minFlipString(s);
    cout << n << endl;
}