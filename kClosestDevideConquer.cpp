#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int dist(vector<int> p);

void partialQuickSort(vector<int> &dists, int low, int high, int K)
{
    if(low >= high)
    {
        return;
    }

    int pivot = dists[low];

    int i = low;
    int j = high;

    while (i<j)
    {
        while ( j > i && dists[j] > pivot )
        {
            j--;
        }

        if(i<j)
        {
            dists[i++] = dists[j];
        }

        while ( i < j && dists[i] < pivot )
        {
            i++;
        }

        if(i<j)
        {
            dists[j--] = dists[i];
        }
    }

    dists[i] = pivot;


    if(K>i)
    {
        partialQuickSort(dists,i+1,high,K);
    }
    else
    {
        partialQuickSort(dists,low,i,K);
    }
}

vector<vector<int>> kClosestDC(vector<vector<int>> &points, int K)
{
    int N = points.size();
    vector<int> dists;
    dists.resize(N);
    for ( int i = 0; i < N; i++ )
    {
        dists[i] = dist(points[i]);
    }

    partialQuickSort(dists,0,dists.size()-1,K);

    int DK = dists[K-1];

    vector<vector<int>> r;
    for ( int i = 0; i < N; i++ )
    {
        if ( dist(points[i]) <= DK )
        {
            r.push_back(points[i]);
        }
    }

    return r;

}

void kClosestMain2()
{
    vector<vector<int>> points;
    //points.push_back({ 3,3 });
    //points.push_back({ 5,-1 });
    //points.push_back({ -2,4});

    //vector<vector<int>> v = kClosestDC(points, 2);

    points.push_back({ -2,-6 });
    points.push_back({ -7,-2 });
    points.push_back({ -9,6});
    points.push_back({ 10,3 });
    points.push_back({ -8,1 });
    points.push_back({ 2,8 });

    vector<vector<int>> v = kClosestDC(points, 5);


    for ( auto i : v )
    {
        cout << i[0] << " " << i[1] << endl;
    }



}