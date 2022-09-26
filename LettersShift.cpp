


#include <vector>
#include <iostream>
#include <string>

using namespace std;

string letterShift(string s, vector<int> &shifts)
{
    int nShift =0;
    for(int i=shifts.size()-1;i>=0;--i)
    {
        nShift += shifts[i]%26;
        s[i]=(s[i]-'a'+nShift)%26+'a';
    }
    return s;
}

void letterShiftMain()
{
    string s = "abc";
    vector<int> shifts = {3,5,9};

    s = letterShift(s,shifts);

    cout << s << endl;

    return;

}