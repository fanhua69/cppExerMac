#pragma once

/* graph.h */

class CVertex
{
public:
  int         m_iValue;
  int         m_iOrderInGraph;
  int         m_nLinkedVertexQty;
  CVertex *   m_pNext;

  CVertex()
  {
    m_iValue = 999;
    m_iOrderInGraph = 0;
    m_nLinkedVertexQty = 0;
    m_pNext = nullptr;
  }
};

class CEdge
{
public:
  int         m_iVertexFrom;
  int         m_iVertexTo;
  int         m_nWeight;

  CEdge()
  {
    m_iVertexFrom = 0;
    m_iVertexTo = 0;
    m_nWeight = 0;
  }
};

struct CGraph
{
  int         m_nVertexQty;
  int         m_nEdgeQty;
  CVertex   **m_ppVertex;

  CGraph()
  {
    m_nEdgeQty = 0;
    m_nVertexQty = 0;
    m_ppVertex = nullptr;
  }
};

void err_quit(char *errorMsg);
