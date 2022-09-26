

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string findSmallestStringKich(string s, int K)
{
    string smalls = s;
    if( K == 1)
    {
        for(int i=0;i<s.length();i++)
        {
            string news = s.substr(i)+s.substr(0,i);
            if(news < smalls)
            {
                smalls = news;
            }
        }
    }
    else
    {
        std::sort(smalls.begin(), smalls.end());
    }

    return smalls;
}

void smallestStringKickMain()
{
    string s = "cba";
    cout << findSmallestStringKich(s,1);
    cout << findSmallestStringKich(s, 2);
}
