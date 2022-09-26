#pragma once

#define NULL 0

class CMyListNode
{
public:
  CMyListNode (int n)
  {
    m_nValue  = n;
    m_pNext   = NULL;
  }

  ~CMyListNode()
  {
    //if(m_pNext)
    //{
    //  delete m_pNext;
    //  m_pNext = NULL;
    //}
  }

  CMyListNode & setNext(CMyListNode* node)
  {
    m_pNext = node;
    return *this;
  }

  CMyListNode & append(CMyListNode* node)
  {
    if(m_pNext)
    {
      delete m_pNext;
      m_pNext = NULL;
    }

    m_pNext = node;

    return *this;
  }

  CMyListNode * next()
  {
    return m_pNext;
  }

private:
  int m_nValue;
  CMyListNode *m_pNext;
};
