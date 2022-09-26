
#include <vector>
#include <iostream>
#include <string>
using namespace std;


bool isChar(char c)
{
    return c >= 'a' && c <= 'z';
}

bool isMatch(string s, string p)
{
    int k = 0;
    int i=0;
    while(i<p.size())
    {
        if(p[i]=='.' 
           && i < p.size() - 1
           && p[i + 1] == '*')
        {
            if(i <p.size()-2 && isChar(p[i + 2]))
            {
                char c = p[i+2];
                i++;
                i++;

                while ( k<s.size() && s[k] != c )
                {
                    k++;
                }
            }
            else
            {
                return true;
            }
        }

        else if (   isChar(p[i]) 
            && i < p.size() - 1 
            && p[i + 1] == '*' )
        {
            char c = p[i];
            i+=2;

            while(p[i] == c)
            {
                p.erase(i);
            }

            while ( k < s.size() && s[k] == c )
            {
                k++;
            }
        }

        else if (isChar(p[i]))
        {
            if(s[k] != p[i])
            {
                return false;
            }
            i++;
            k++;
        }

        else if ( p[i] == '.' )
        {
            k++;
            i++;
        }

    }

    if(k<s.size() || i<p.size())
    {
        return false;
    }

    return true;

}

enum Match
{
    NotSet,
    NotMatch,
    IsMatch
};

Match **memo;

bool DynPro(int i, int j, string s, string p)
{
    if ( memo[i][j] != NotSet )
    {
        return memo[i][j] == IsMatch;
    }

    bool answer;
    if ( j == p.length() )
    {
        answer = (i == s.length());
    }
    else
    {
        bool firstMatch = (i < s.length() && (p[j] == s[i] || p[j] == '.'));

        if ( j + 1 < p.length() && p[j + 1] == '*' )
        {
            answer = (DynPro(i, j + 2, s, p) || firstMatch && DynPro(i + 1, j, s, p));
        }
        else
        {
            answer = firstMatch && DynPro(i + 1, j + 1, s, p);
        }
    }
    
    memo[i][j] = answer ? IsMatch: NotMatch;

    return answer;
}

bool isMatch3(string text, string pattern)
{
    memo = new Match*[text.length() + 1];
    for ( int i = 0; i < text.length() + 1; i++ )
    {
        memo[i] = new Match[pattern.length() + 1];
        for ( int j = 0; j < pattern.length() + 1; j++ )
        {
            memo[i][j] = NotSet;
        }
    }

    return DynPro(0, 0, text, pattern);
}

bool isMatch4(string s, string p);


void isMatchMain()
{
    string s="ab";
    string p = "a";
    bool b = isMatch(s,p);
    cout << b << endl;  // false

    s = "aab";
    p = "c*a*b"; 
    b = isMatch(s, p);
    cout << b << endl;  // true

    s = "abcd";
    p = "d*";
    b = isMatch(s, p);
    cout << b << endl;  // false

    s = "ab";
    p = ".*c";
    b = isMatch(s, p);
    cout << b << endl;  //false

    s = "ab";
    p = ".*";
    b = isMatch(s, p);
    cout << b << endl;  //true

    s = "aaa";
    p = "a*a";
    b = isMatch(s, p);
    cout << b << endl;  //true

    s = "aaa";
    p = "ab*a*c*a";
    b = isMatch4(s, p);
    cout << b << endl;  //true
}