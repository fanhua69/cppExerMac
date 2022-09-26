
#include "graph.h"
#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <queue>
#include <stack>

#include <iostream>

using namespace std;

/* graph.c */

void err_quit(char *errorMsg)
{
  cout << errorMsg << endl;
}

static CVertex *createVertex(int iOrderInGraph,
                             int nWeight)
{
  CVertex *pVertex = new CVertex;
  if ( pVertex == NULL )
  {
    err_quit("malloc error");
  }

  pVertex->m_iOrderInGraph    = iOrderInGraph;
  pVertex->m_nLinkedVertexQty = nWeight;
  pVertex->m_iValue           = iOrderInGraph;
  pVertex->m_pNext            = NULL;

  return pVertex;
}

static void destroyVertex(CVertex *u)
{
  delete (u);
}

static void addVertex(CVertex *pVertexAdding, 
                      CVertex *pVertexTo)
{
  pVertexAdding->m_pNext  = pVertexTo->m_pNext;
  pVertexTo->m_pNext      = pVertexAdding;
}

static CEdge *createEdge(int iVertexFrom, 
                         int iVertexTo, 
                         int nWeight)
{
  CEdge *pEdge = new CEdge;
  if ( pEdge == NULL )
  {
    err_quit("malloc error");
  }

  pEdge->m_iVertexFrom  = iVertexFrom;
  pEdge->m_iVertexTo    = iVertexTo;
  pEdge->m_nWeight      = nWeight;

  return pEdge;
}

static void destroyEdge(CEdge *e)
{
  delete e;
}

CGraph *createGraph(  int edgeArray[][2],
                      int nVertexQty, 
                      int nEdgeQty)
{
  CGraph *pGraph = NULL;
  CVertex *pVertex = NULL;
  int nVertexFromNo, nVertexToNo;
  int i, j;

  pGraph = new CGraph;
  if ( pGraph == NULL )
  {
    err_quit("malloc error");
  }

  pGraph->m_nVertexQty    = nVertexQty;
  pGraph->m_nEdgeQty      = nEdgeQty;
  pGraph->m_ppVertex      = (CVertex **)malloc(sizeof(CVertex *)*(nVertexQty + 1));
  if ( pGraph->m_ppVertex == NULL )
  {
    err_quit("malloc error");
  }

  for ( i = 0; i < nVertexQty; i++ )
  {
    pGraph->m_ppVertex[i] = createVertex(i, 0);
  }

  for ( j = 0; j < nEdgeQty; j++ )
  {
    nVertexFromNo  = edgeArray[j][0];
    nVertexToNo    = edgeArray[j][1];
    pVertex        = createVertex(nVertexToNo, 1);
    addVertex(pVertex, pGraph->m_ppVertex[nVertexFromNo]);
    pGraph->m_ppVertex[nVertexToNo]->m_nLinkedVertexQty++;
  }
  return pGraph;
}

CGraph *createWeightedGraph(int edgeArray[][3],
                            int nVertexQty, 
                            int nEdgeQty)
{
  CGraph *pGraph    = NULL;
  CVertex *pVertex  = NULL;
  int iVertexFrom, iVertexTo;
  int i, j;

  pGraph = new CGraph();
  if ( pGraph == NULL )
  {
    err_quit("malloc error");
  }

  pGraph->m_nVertexQty  = nVertexQty;
  pGraph->m_nEdgeQty    = nEdgeQty;
  pGraph->m_ppVertex    = new CVertex* [nVertexQty];
  if ( pGraph->m_ppVertex == NULL )
  {
    err_quit("malloc error");
  }

  for ( i = 0; i < nVertexQty; i++ )
  {
    pGraph->m_ppVertex[i] = createVertex(i, 0);
  }

  for ( j = 0; j < nEdgeQty; j++ )
  {
    iVertexFrom = edgeArray[j][0];
    iVertexTo   = edgeArray[j][1];
    pVertex     = createVertex(iVertexTo, edgeArray[j][2]);

    addVertex(pVertex, pGraph->m_ppVertex[iVertexFrom]);

    pGraph->m_ppVertex[iVertexTo]->m_nLinkedVertexQty++;
  }
  return pGraph;
}

void destroyGraph(CGraph *pGraph)
{
  CVertex *pVertex1, *pVertex2;
  int i;

  for ( i = 0; i < pGraph->m_nVertexQty; i++ )
  {
    pVertex2 = pGraph->m_ppVertex[i];
    while ( pVertex2 )
    {
      pVertex1 = pVertex2;
      pVertex2 = pVertex2->m_pNext;
      destroyVertex(pVertex1);
    }
  }
  free(pGraph->m_ppVertex);
  free(pGraph);
}

void printGraph(CGraph *pGraph)
{
  CVertex *pVertex;
  int i;

  for ( i = 0; i < pGraph->m_nVertexQty; i++ )
  {
    printf("(%d,%d):",  pGraph->m_ppVertex[i]->m_iOrderInGraph, 
                        pGraph->m_ppVertex[i]->m_nLinkedVertexQty);

    pVertex = pGraph->m_ppVertex[i]->m_pNext;
    while ( pVertex )
    {
      printf(" (%d,%d)",  pVertex->m_iOrderInGraph, 
                          pVertex->m_nLinkedVertexQty);
      pVertex = pVertex->m_pNext;
    }
    printf("\n");
  }
}

void BFS(CGraph *pGraph)
{
  bool *bVisited = new bool[pGraph->m_nVertexQty];
  for(int i = 0;i<pGraph->m_nVertexQty;i++)
  {
    bVisited[i] = false;
  }

  std::queue<int> queueForTraverse;
  for(int i=0;i< pGraph->m_nVertexQty;i++)
  {
    if(bVisited[i])
    {
      continue;
    }

    bVisited[i] = true;
    
    queueForTraverse.push(i);

    CVertex * pVertex = pGraph->m_ppVertex[i];
    cout << pVertex->m_iValue << endl;
    while(!queueForTraverse.empty())
    {
      int iVertex = queueForTraverse.front();
      queueForTraverse.pop();

      CVertex * pVertex = pGraph->m_ppVertex[iVertex];
      while(pVertex)
      {
        if(!bVisited[pVertex->m_iOrderInGraph] )
        {
          bVisited[pVertex->m_iOrderInGraph] = true;
          queueForTraverse.push(pVertex->m_iOrderInGraph);
          cout << pVertex->m_iValue << endl;
        }
        pVertex= pVertex->m_pNext;
      }
    }
  }

  delete []bVisited;
}

void DFS(CGraph *pGraph)
{
  bool *bVisited = new bool[pGraph->m_nVertexQty];
  for ( int i = 0; i<pGraph->m_nVertexQty; i++ )
  {
    bVisited[i] = false;
  }

  std::stack <int> stackForTraverse;
  for ( int i = 0; i< pGraph->m_nVertexQty; i++ )
  {
    if ( bVisited[i] )
    {
      continue;
    }

    stackForTraverse.push(i);

    CVertex * pVertex = pGraph->m_ppVertex[i];
    while ( !stackForTraverse.empty() )
    {
      int iVertex = stackForTraverse.top();
      stackForTraverse.pop();
      cout << iVertex << endl;
      bVisited[iVertex] = true;

      
      CVertex * pVertex = pGraph->m_ppVertex[iVertex];

      while(pVertex)
      {
        if(!bVisited[pVertex->m_iOrderInGraph])
        {
          stackForTraverse.push(pVertex->m_iOrderInGraph);
        }

        pVertex = pVertex->m_pNext;
      }
    }
  }

  delete[]bVisited;
}


void graphMain()
{
  int edgeArray [10][3] = 
    { 0,2,2,
      0,3,3,
      0,4,4,
      0,5,5,
      1,6,6,
      2,7,7,
      3,7,8,
      4,8,9,
      5,8,10,
      1,6,6
    };

  int nVertexQty = 9;
  int nEdgeQty = 10;
                        
  CGraph * pGraph  = createWeightedGraph(edgeArray,
                      nVertexQty,
                      nEdgeQty);

  if(!pGraph)
  {
    return;
  }

  printGraph(pGraph);
  DFS(pGraph);

  delete pGraph;
  pGraph = NULL;
}