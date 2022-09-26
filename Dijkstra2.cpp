
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

void Dijkstra2(vector<vector<int>> &g, int next, vector<int> &l, vector<int> &p)
{
    //int nodes = g.size();

    //for(int i=0;i<nodes;i++)
    //{
    //    if(i==head)
    //    {
    //        continue;
    //    }

    //    int l1 = g[head][i] < g[i][head] ? g[head][i] : g[i][head];

    //    if( l1!=INT_MAX && find(p.begin(),p.end(),i) == p.end())
    //    {
    //        int newLen = l[head]+ l1;
    //        if(newLen<l[i])
    //        {
    //            l[i] = newLen;
    //            p[i] = head;

    //            Dijkstra2(g,i,goal,l,p);
    //        }
    //    }
    //}
}

void Dijkstra1(vector<vector<int>> &g, int head, int goal, vector<int> &path)
{
    int N = INT_MAX;
    int nodes = g.size();
    vector<int> l(nodes, INT_MAX);
    vector<int> p(nodes, -1);
    l[head] = 0;

  //  Dijkstra2(g,head,goal,l,p);

    int i=goal;
    while(i!=-1)
    {
        path.push_back(i);
        i=p[i];
    }
    std::reverse(path.begin(),path.end());

    return;
}


void DijkstraMain()
{
    int N = 5;
    vector<vector<int>> g(N,vector<int>(N,INT_MAX));
    g[0][1] = 2;
    g[0][2] = 3;
    g[0][3] = 10;
    g[1][3] = 6;
    g[2][3] = 4;
    g[1][4] = 1;
    g[4][3]= 2;

    vector<int>path;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            path.clear();
            Dijkstra1(g,i,j,path);
            cout << "From " << i << " to " << j << ":" ;
            for(auto i: path)
            {
                cout << i << ",";
            }

            cout << endl;
        }
    }

}