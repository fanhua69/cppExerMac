

#include <concurrent_priority_queue.h>
#include <queue>
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class greaters
{
public:
    bool operator ()(const int &i, const int &j)
    {
        return i>j;
    }
};

class MedianFinder
{
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if(maxHeap.size() > minHeap.size())
        {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else
        {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if(minHeap.size() == 0 && maxHeap.size()==0)
        {
            return 0;
        }

        if(minHeap.size()> maxHeap.size())
        {
            return minHeap.top();
        }
        else if(maxHeap.size()>minHeap.size())
        {
            return maxHeap.top();
        }
        else
        {
            return (maxHeap.top()+minHeap.top())/2.0;
        }

    }

    std::priority_queue<int, std::vector<int>> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};

void priorityQueueMain()
{
    std::vector<int> a={8,7,6,5,4,3,2,1};
    
    
    std::make_heap(a.begin(),a.end(),greaters());

    for(auto i:a)
    {
        cout << i << endl;
    }
    cout<< endl <<endl<<endl;

    MedianFinder f;
    //f.addNum(1);

    cout << f.findMedian() << endl;


}

