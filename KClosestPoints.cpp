#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;


int dist(vector<int> p)
{
    return p[0] * p[0] + p[1] * p[1];
}

vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
{
    int N = points.size();
    vector<int> dists;
    dists.resize(N);
    for(int i=0;i<N;i++)
    {
        dists[i] = dist(points[i]);
    }

    std::sort(dists.begin(),dists.end());

    int DK = dists[K-1];

    vector<vector<int>> r;
    for(int i=0;i<N;i++)
    {
        if(dist(points[i]) <= DK)
        {
            r.push_back(points[i]);
        }
    }

    return r;

}

void kClosestMain()
{
    vector<vector<int>> points;
    points.push_back({1,3});
    points.push_back({-2,2});


    vector<vector<int>> v = kClosest(points,1);

    for(auto i : v)
    {
        cout << i[0] << " " << i[1] << endl;
    }



}