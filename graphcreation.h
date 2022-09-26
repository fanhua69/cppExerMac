#pragma once

#include <vector>
#include <set>
#include <stack>

using namespace std;

class CFHGraphEdge
{
public:
    int from;
    int to;
    int weight;

    CFHGraphEdge()
    {
        from = to = weight = 0;
    }

    CFHGraphEdge(int f, int t, int w)
    {
        from = f;
        to = t;
        weight = w;
    }
};

class CFHGraphNode
{
public:
    CFHGraphNode();
    static CFHGraphNode *   createNode(int iOrderInGraph, int iNodeProperty);
    CFHGraphNode        *   findTail();
    void                    destroy();

    int             iNodeProperty;
    int             iNodeOrderInGraph;
    CFHGraphNode *  pNextNode;
};


class CFHGraph
{
public:
    CFHGraph();
    void destroyGraph();
    bool addEdge(CFHGraphEdge &edge);
    bool create(int nNodeQty, std::vector<CFHGraphEdge> & edges);
    int  getVertexQty(){ return m_headNodes.size();}
    bool findPath(int fromNode, int toNode, std::set<int> &visited, std::stack<int> &path);
    bool findAllPaths(int fromNode,int toNode,vector<int> &visited,stack<int> &path,vector<stack<int>> &allPaths);
    std::vector<int> findLongestPathInDAG();
    void topologicalSortNode(CFHGraphNode *node, std::set<int> &nodeVisited, std::stack<CFHGraphNode*> & nodeOrdered);
    std::stack<CFHGraphNode*> topologicalSort();


    std::vector<CFHGraphNode*> BreadthFirstTraversal();
    std::vector<CFHGraphNode*> DepthFirstTraversal();


    std::vector<CFHGraphNode*> m_headNodes;
};


