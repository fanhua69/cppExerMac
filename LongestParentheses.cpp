

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool isValis(string s)
{
    stack<char> p;
    for ( int i = 0; i < s.size(); i++ )
    {
        if ( s[i] == '(' )
        {
            p.push('p');
        }
        else if ( s[i] == ')' )
        {
            if ( p.size() > 0 )
            {
                p.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return p.size()==0;

}


int longestValidParentheses(string s)
{
    int l=0;
    int maxl = 0;
    for(int i=0;i<s.size();i++)
    {
        for(int j=i+1;j<s.size();j++)
        {
            string s1=s.substr(i,j-i+1);
            if(isValis(s1))
            {
                maxl = maxl>s1.size()? maxl:s1.size();
            }
        }
    }

    return maxl;
}


int longestValidParentheses2(string s)
{
    if ( s.size() < 2 )
    {
        return 0;
    }

    vector<int> maxlen(s.size(), 0);
    maxlen[0] = 0;
    for ( int i = 1; i < s.size(); i++ )
    {
        if ( s[i - 1] == '(' )
        {
            if ( i >= 2 )
            {
                maxlen[i] = maxlen[i - 2] + 2;
            }
            else
            {
                maxlen[i] = 2;
            }
        }
        else if ( i - maxlen[i - 1] - 1 >= 0 )
        {
            int nPre = i - maxlen[i - 1] - 1;
            char c = s[nPre];
            if ( c == '(' )
            {
                maxlen[i] = maxlen[i - 1] + 2;

                if ( nPre - 1 >= 0 )
                {
                    maxlen[i] += maxlen[nPre - 1];
                }
            }
        }
    }

    int ml = 0;
    for ( int i = 0; i < maxlen.size(); i++ )
    {
        ml = ml > maxlen[i] ? ml : maxlen[i];
    }

    return ml;
}

void findLongestParenthesesMain()
{
    string s="(())";
    int n = longestValidParentheses2(s);
    cout << n << endl;

    s = ")()())";
    n = longestValidParentheses2(s);
    cout << n << endl;

}