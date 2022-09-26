


#include "graphcreation.h"
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

CFHGraphNode::CFHGraphNode()
{
    iNodeProperty = 0;
    iNodeOrderInGraph = -1;
    pNextNode = NULL;
}

CFHGraphNode * CFHGraphNode::createNode(int iOrderInGraph, int iNodeProperty)
{
    CFHGraphNode *pNode = new CFHGraphNode;
    pNode->iNodeProperty = iNodeProperty;
    pNode->iNodeOrderInGraph = iOrderInGraph;
    pNode->pNextNode = NULL;

    return pNode;
}

CFHGraphNode * CFHGraphNode::findTail()
{
    if(!pNextNode)
    {
        return this;
    }
    return pNextNode->findTail();
}

void CFHGraphNode::destroy()
{
    if(pNextNode)
    {
        pNextNode->destroy();
        delete pNextNode;
    }
}


CFHGraph::CFHGraph()
{
}

void CFHGraph::destroyGraph()
{
    for(unsigned int i=0;i<m_headNodes.size();i++)
    {
        if(m_headNodes[i])
        {
            m_headNodes[i]->destroy();
            delete m_headNodes[i];
        }
    }
    m_headNodes.clear();
}

bool CFHGraph::addEdge(CFHGraphEdge &edge)
{
    if(edge.from < 0 || edge.from >= m_headNodes.size() ||
        edge.to < 0  || edge.to   >= m_headNodes.size())
    {
        return false;
    }

    // add an edge from fromNode to toNode:
    CFHGraphNode *pTailNode = m_headNodes[edge.from]->findTail();
    if(!pTailNode)
    {
        return false;
    }

    CFHGraphNode *pNewNode = CFHGraphNode::createNode(edge.to,edge.weight);
    pTailNode->pNextNode = pNewNode;

    return true;
}

bool CFHGraph::create(int nNodeQty, std::vector<CFHGraphEdge> & edges)
{
    destroyGraph();
    m_headNodes.reserve(nNodeQty);
    for(int i=0;i<nNodeQty;i++)
    {
        m_headNodes.push_back(CFHGraphNode::createNode(i,i));
    }

    for(unsigned int i=0;i<edges.size();i++)
    {
        CFHGraphEdge &edge = edges[i];
        addEdge(edge);
    }

    return true;
}



bool CFHGraph::findPath(int fromNode, int toNode,std::set<int> &visited, std::stack<int> &path)
{
    visited.insert(fromNode);

    path.push(fromNode);
    if(fromNode == toNode)
    {
        return true;
    }

    CFHGraphNode *nextNode = m_headNodes[fromNode]->pNextNode;
    while(nextNode)
    {
        if(visited.find(nextNode->iNodeOrderInGraph) == visited.end())
        {
            if(findPath(nextNode->iNodeOrderInGraph,toNode,visited, path))
            {
                return true;
            }
            else
            {
                path.pop();
            }
        }

        nextNode = nextNode->pNextNode;
    }

    return false;
}

bool CFHGraph::findAllPaths(int                 fromNode,
                            int                 toNode,
                            vector<int>         &visited,
                            stack<int>          &path,
                            vector<stack<int>>  &allPaths)
{
    visited.push_back(fromNode);
    path.push(fromNode);
    if ( fromNode == toNode )
    {
        return true;
    }

    CFHGraphNode *nextNode = m_headNodes[fromNode]->pNextNode;
    while ( nextNode )
    {
        if ( std::find(visited.begin(),visited.end(),nextNode->iNodeOrderInGraph) == visited.end() )
        {
            if ( findAllPaths(nextNode->iNodeOrderInGraph, toNode, visited, path, allPaths) )
            {
                allPaths.push_back(path);

                stack<int>pathback = path;
                for(unsigned int i=0;i<path.size()-1;i++)
                {
                    vector<int>::iterator it = std::find(visited.begin(), visited.end(), pathback.top());
                    if(it != visited.end())
                    {
                        visited.erase(it);
                    }
                    pathback.pop();
                }
            }
            path.pop();
        }

        nextNode = nextNode->pNextNode;
    }

    return false;
}


std::vector<CFHGraphNode*> CFHGraph::BreadthFirstTraversal()
{
    std::map<int, bool> bNodeVisited;

    std::queue<CFHGraphNode*> nodeToVisit;
    std::vector<CFHGraphNode*> nodeBFT;

    for(unsigned int i=0;i<m_headNodes.size();i++)
    {
        if(bNodeVisited[i])
        {
            continue;
        }

        nodeToVisit.push(m_headNodes[i]);

        while(!nodeToVisit.empty())
        {
            CFHGraphNode *pVisitingNode = nodeToVisit.front();

            nodeBFT.push_back(pVisitingNode);
            bNodeVisited[pVisitingNode->iNodeOrderInGraph] = true;

            pVisitingNode = m_headNodes[pVisitingNode->iNodeOrderInGraph];
            while(pVisitingNode)
            {
                if(!bNodeVisited[pVisitingNode ->iNodeOrderInGraph])
                {
                    nodeToVisit.push(pVisitingNode);
                }
                pVisitingNode = pVisitingNode->pNextNode;
            }

            nodeToVisit.pop();
        }
    }

    return nodeBFT;
}

std::vector <CFHGraphNode*> CFHGraph::DepthFirstTraversal()
{
    std::map<int, bool> nodeVisited;
    std::stack<CFHGraphNode*> nodeToVisit;

    std::vector<CFHGraphNode*> nodeReturn;

    for(unsigned int i=0;i<m_headNodes.size();i++)
    {
        if(nodeVisited[i])
        {
            continue;
        }

        nodeToVisit.push(m_headNodes[i]);

        while(nodeToVisit.size()>0)
        {
            CFHGraphNode *pNode = nodeToVisit.top();
            nodeToVisit.pop();
            if(nodeVisited[pNode->iNodeOrderInGraph])
            {
                continue;
            }

            // Visit the node:
            nodeReturn.push_back(pNode);
            nodeVisited[pNode->iNodeOrderInGraph] = true;

            // Check the nodes next to this node:
            pNode = m_headNodes[pNode->iNodeOrderInGraph]->pNextNode;
            while(pNode)
            {
                if(!nodeVisited[pNode->iNodeOrderInGraph])
                {
                    nodeToVisit.push(pNode);
                }
                pNode = pNode->pNextNode;
            }
        }
    }

    return nodeReturn;

}

std::vector<int> CFHGraph::findLongestPathInDAG()
{
    std::stack<CFHGraphNode*> nodesSorted = topologicalSort();

    std::vector<int> longestPaths;

    longestPaths.clear();
    const int MMAX = -99999999;
    for(int i=0;i < getVertexQty();i++)
    {
        longestPaths.push_back(MMAX);
    }

    int i = 0;
    while(nodesSorted.size() > 0)
    {
        CFHGraphNode *node = nodesSorted.top();
        if(i == 0)
        {
            longestPaths[node->iNodeOrderInGraph] = 0;
        }

        CFHGraphNode *nextNode = m_headNodes[node->iNodeOrderInGraph]->pNextNode;
        while(nextNode)
        {
            if(longestPaths[nextNode->iNodeOrderInGraph] < longestPaths[node->iNodeOrderInGraph] + nextNode->iNodeProperty)
            {
                longestPaths[nextNode->iNodeOrderInGraph] = longestPaths[node->iNodeOrderInGraph] + nextNode->iNodeProperty;
            }
            nextNode = nextNode ->pNextNode;
        }
        
        i++;
        nodesSorted.pop();
    }

    return longestPaths;
}



void FHGraphMain()
{
    int nNodeQty = 14;
    std::vector<CFHGraphEdge> edges;
    
    edges.push_back({0, 1, 1});
    edges.push_back({0, 2, 1});
    edges.push_back({0, 3, 1});
    edges.push_back({ 0, 4, 1 });

    edges.push_back({ 1, 5, 1 });
    edges.push_back({ 1, 6, 1 });
    
    edges.push_back({ 2, 7, 1 });
    edges.push_back({ 2, 8, 1 });
    edges.push_back({ 3, 9, 1 });
    edges.push_back({ 4, 10, 1 });
    edges.push_back({ 4, 11, 1 });
    edges.push_back({ 5, 12, 1 });
    edges.push_back({ 8, 13, 1 });
    edges.push_back({ 9, 8, 1 });
    edges.push_back({ 3, 2, 1 });

    CFHGraph g;
    g.create(nNodeQty,edges);
    
    std::vector<int>visited;
    vector<stack<int>>allPaths;
    std::stack<int> path;

    g.findAllPaths(0,13,visited,path,allPaths);

    std::vector<CFHGraphNode*> v = g.BreadthFirstTraversal();

    std::vector <CFHGraphNode*> v2 = g.DepthFirstTraversal();

    std::vector<int> lp = g.findLongestPathInDAG();


}