
#include <set>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class medianFinderSet
{
protected:
    multiset<int> _data;
    multiset<int>::iterator _itleft;
    multiset<int>::iterator _itRight;

public:

    medianFinderSet()
    {
        _itRight = _itleft = _data.begin();
    }

    void addNum(int n)
    {
        _data.insert(n);
    }
};