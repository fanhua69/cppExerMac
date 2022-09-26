
///////////////////////////////////////////////
// copyright:
// author:
// date:
//////////////////////////////////////////////

#ifndef PTHREADTEST_H
#define PTHREADTEST_H

#include "stdio.h"

#define NUM_THREADS 100

class MyQueueNode
{
public:
  MyQueueNode()
  {
    m_pNext = NULL;
    m_iValue = 0;
  }

  virtual ~MyQueueNode()
  {
    m_pNext = NULL;
  }

  MyQueueNode(int nValue)
  {
    m_iValue = nValue;
    m_pNext = NULL;
  }

  MyQueueNode(const MyQueueNode &other)
  {
    m_iValue = other.m_iValue;
    m_pNext = other.m_pNext;
  }

  MyQueueNode & operator = (const MyQueueNode &other)
  {
    if ( this == &other )
    {
      return *this;
    }

    m_iValue = other.m_iValue;
    m_pNext = other.getNext();

    return *this;
  }

  int getValue()
  {
    return m_iValue;
  }

  MyQueueNode * getNext() const
  {
    return m_pNext;
  }

  MyQueueNode operator ++ (int)
  {
    MyQueueNode node = *this;

    m_iValue++;

    return node;
  }

  MyQueueNode & operator ++()
  {
    m_iValue++;
    return *this;
  }

  void append(MyQueueNode *node)
  {
    if(m_pNext != NULL || node == NULL)
    {
      return;
    }

    m_pNext = node;
  }

private:
  int           m_iValue;
  MyQueueNode * m_pNext;
};

class MyQueue
{
public:
  MyQueue()
  {
    m_pQueueHead = NULL;
    m_pQueueTail = NULL;
  }

  virtual ~MyQueue()
  {
    clearQueue();
  }

  MyQueue & append(MyQueueNode * node);
  MyQueueNode * removeHead();
  int getSize();
  void waitEmpty();
  void clearQueue();


private:
  MyQueueNode *m_pQueueHead;
  MyQueueNode *m_pQueueTail;
};


#endif