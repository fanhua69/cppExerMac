

#include "mylist.h"
#include <stack>

CMyListNode * checkloopinlist(CMyListNode *head)
{
  CMyListNode *iter1 = head;
  CMyListNode *iter2 = head;


  CMyListNode * meetNode = NULL;
  while(iter1 && iter2)
  {
    iter1 = iter1->next();
    iter2 = iter2->next();
    if(iter2)
    {
      iter2 = iter2->next();
    }

    if(iter1 == iter2)
    {
      meetNode = iter1;
      break;
    }
  }

  if(!meetNode)
  {
    return NULL;
  }

  iter1 = head;
  iter2 = meetNode;

  CMyListNode *loopHead = NULL;
  while(iter1 && iter2)
  {
    iter1 = iter1->next();
    iter2 = iter2->next();

    if(iter1 == iter2)
    {
      loopHead = iter1;
      break;
    }
  }

  return loopHead;
}

void checkLoopInListMain()
{
  CMyListNode * node1 = new CMyListNode(1);
  CMyListNode * node2 = new CMyListNode(2);
  CMyListNode * node3 = new CMyListNode(3);
  CMyListNode * node4 = new CMyListNode(4);
  CMyListNode * node5 = new CMyListNode(5);
  CMyListNode * node6 = new CMyListNode(6);
  CMyListNode * node7 = new CMyListNode(7);
  
  node1->append(node2);
  node2->append(node3);
  node3->append(node4);
  node4->append(node5);
  node5->append(node6);
  node6->append(node7);
  //node7->append(node3);

  CMyListNode * pLoopHead = checkloopinlist(node1);

  return ;
}