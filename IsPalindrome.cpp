

#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool isPalindrome2(int x)
{
    if(x < 0 || ( x %10 ==0 && x !=0))
    {
        return false;
    }

    int reversed = 0;

    while(x > reversed)
    {
        reversed = reversed*10+x%10;
        x/=10;
    }

    return x == reversed || x == reversed / 10;
}


bool isPalindrome(int x)
{
    vector<char> s;
    while(int(x) > 0)
    {
        int n = x%10;
        s.push_back('0'+n);
        x=int(x/10);
    }

    int half;
    if(s.size() % 2 !=0)
    {
        half= s.size()/2;
    }
    else
    {
        half = s.size()/2-1;
    }

    bool isPalindrome = true;
    for(int i=0;i<=half;i++)
    {
        if(s[i] != s[s.size()-1-i])
        {
            isPalindrome = false;
            break;
        }
    }

    return isPalindrome;
}

void isPalindromeMain()
{
    bool b = isPalindrome2(121);

    cout << b << endl;

    b = isPalindrome2(20);

    cout << b << endl;


    b = isPalindrome2(12344321);

    cout << b << endl;


}