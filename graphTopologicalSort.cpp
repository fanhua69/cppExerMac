

#include "graphcreation.h"

void CFHGraph::topologicalSortNode(CFHGraphNode *node, 
                                   std::set<int> &nodeVisited,
                                   std::stack<CFHGraphNode*> & nodeOrdered)
{
    CFHGraphNode * nextNode = m_headNodes[node->iNodeOrderInGraph]->pNextNode;
    while(nextNode)
    {
        if(nodeVisited.find(nextNode->iNodeOrderInGraph) == nodeVisited.end())
        {
            nodeVisited.insert(nextNode->iNodeOrderInGraph);
            topologicalSortNode(nextNode,nodeVisited, nodeOrdered);
        }
        nextNode = nextNode->pNextNode;
    }

    nodeOrdered.push(node);
}

std::stack<CFHGraphNode*> CFHGraph::topologicalSort()
{
    std::stack<CFHGraphNode*> nodeOrdered;

    std::set<int> nodeVisited;

    for ( unsigned int i = 0; i<m_headNodes.size(); i++ )
    {
        if(nodeVisited.find(m_headNodes[i]->iNodeOrderInGraph)==nodeVisited.end())
        {
            topologicalSortNode(m_headNodes[i],nodeVisited,nodeOrdered);
        }
    }

    return nodeOrdered;
}
