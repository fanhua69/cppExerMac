

#include "mylist.h"

CMyListNode * reverselist(CMyListNode *pHead)
{
  CMyListNode * p1 = pHead;
  CMyListNode * p2 = p1->next();
  p1->setNext(NULL);
  CMyListNode * p3 = NULL;
  while(p2)
  {
    p3 = p2->next();
    p2->setNext(p1);
    p1 = p2;
    p2 = p3;
  }

  return p1;
}

void reverseListMain()
{
  CMyListNode *p1= new CMyListNode(1);
  CMyListNode *p2= new CMyListNode(2);
  CMyListNode *p3= new CMyListNode(3);
  CMyListNode *p4= new CMyListNode(4);
  CMyListNode *p5= new CMyListNode(5);
  
  p1->append(p2);
  p2->append(p3);
  p3->append(p4);
  p4->append(p5);

  CMyListNode *pHead = reverselist(p1);
}