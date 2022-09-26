

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class medianFinder
{
public:
    void addNum(int n)
    {
        if(!_r.empty() && n > _r.top())
        {
            _r.push(n);
        }
        else
        {
            _l.push(n);
        }

        while(_l.size()>(_r.size()+1))
        {
            int n = _l.top();
            _r.push(n);
            _l.pop();
        } 
        
        while(_r.size()>_l.size())
        {
            int n = _r.top();
            _l.push(n);
            _r.pop();
        }
    }

    double getMedian()
    {
        if(_l.size()==_r.size())
        {
            return static_cast<double>((_l.top() + _r.top())/2.0);
        }
        else
        {
            return static_cast<double>(_l.top());
        }
    }

protected:

    priority_queue<int,vector<int>,less<int>> _l;
    priority_queue<int,vector<int>,greater<int>> _r;
};

double findMedianOfStream(vector<int> stream)
{
    medianFinder a;
    for(auto i : stream)
    {
        a.addNum(i);
    }

    return a.getMedian();
}

void findMedianOfStreamMain()
{
    vector<int> a = {4,5,6,9,7,8,1,2,3};
    double m = findMedianOfStream(a);
    cout << m << endl;
}