

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int shortestPathLength(vector<vector<int>>& graph)
{
    class NODE
    {
    public:
        int node;
        int state;
        NODE(int n, int s)
        {
            node = n;
            state =s ;
        }
    };
    const int n = graph.size();
    const int kAns = (1<<n)-1;
    queue<NODE>q;

    vector<vector<int>> visited(n,vector<int>(1<<n));

    for(int i=0;i<graph.size();++i)
    {
        q.push({i,1<<i});
    }

    int steps = 0;
    while(!q.empty())
    {
        int s = q.size();
        while(s--)
        {
            NODE p = q.front();
            q.pop();
            int node = p.node;
            int state = p.state;
            if(state == kAns)
            {
                return steps;
            }

            if(visited[node][state])continue;
            visited[node][state] = 1;
            for(int next:graph[node])
            {
                q.push({next,state | (1 << next)});
            }
        }
        ++steps;
    }
}

int visitNode(vector<vector<int>> &graph, int node, vector<int> &nodeStates, int nAns, int steps)
{
    steps ++;
    for(int i = 0; i< graph[node].size();i++)
    {
        int next = graph[node][i];
        int &visited = nodeStates[node];
        if(visited & (1<<next))
        {
            continue;
        }

        visited |= (1 << next);
        if(visited == nAns)
        {
            return steps;
        }

        int n = visitNode(graph,next,nodeStates,nAns,steps);
        if(n>0)
        {
            return n;
        }
    }

    return -1;
}

int shortestPathLength2(vector<vector<int>> &graph)
{
    const int N = graph.size();
    const int nAns = (1<<N)-1;

    vector<int> nodeStates(N,0);

    int &visited = nodeStates[0];
    int steps = 1;
    for(int i = 0;i <N;i++)
    {
        visited |= 1<<i;
        if(visitNode(graph, i, nodeStates, nAns,steps)>0)
        {
            return steps;
        }
    }
}


int shortestPathLengthBFS(vector<vector<int>> &graph)
{
    const int N = graph.size();
    int nAns = (1 << N) - 1;

    vector<vector<int>> visited(N,vector<int>(1<<N,0));

    queue<pair<int,int>> q;
    for(int i=0;i<N;i++)
    {
        q.push({i, 1<<i});
    }

    int steps = 0;
    while(q.size()>0)
    {
        int s =q.size();
        while(s--)
        {
            auto node = q.front();
            q.pop();

            int n =node.first;
            int state = node.second;
            if ( state == nAns )
            {
                return steps;
            }

            if ( visited[n][state] == true )
            {
                continue;
            }

            for(int i=0;i<graph[n].size();i++)
            {
                q.push({ graph[n][i], state | (1 << i) });
            }
        }
        steps++;
    }

    return -1;
}


void shortestPathLengthMain()
{
    vector<vector<int>> graph = {{1,2,3},{0},{0},{0}};
    int n = shortestPathLength(graph);

    cout << n << endl;
}


