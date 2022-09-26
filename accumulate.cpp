
#include <iostream>

#include <numeric>
#include <list>

using namespace std;

void accumulateMain()
{
    list<int> list1 = {1,2,3,4,5};
    
    int n= std::accumulate(list1.begin(),list1.end(), 2);

    cout<< n<< endl;

}