
#include <unordered_map>

#define NULL 0

struct Node
{
  char data;
  Node *next;
  Node *random;

  Node(char d)
  {
    data = d;
    next = NULL;
    random = NULL;
  }
};

Node * cloneList(Node *pHead)
{
  if(!pHead)
  {
    return NULL;
  }

  
  std::unordered_map<Node *, Node *> mapIndices;

  Node *pNewHead = NULL;
  Node *pPrev = NULL;
  Node *pNode = pHead;
  while(pNode)
  {
    Node *pNew = new Node(pNode->data);
    pNew->random = pNode->random;

    mapIndices[pNode] = pNew;

    if(pPrev == NULL)
    {
      pNewHead = pNew;
      pPrev = pNewHead;
    }
    else
    {
      pPrev ->next = pNew;
    }

    pNode = pNode->next;
    pPrev = pNew;
  }

  pNode = pNewHead;
  while ( pNode )
  {
    if(pNode->random)
    {
      Node *pNewRandom = mapIndices[pNode->random];
      pNode->random = pNewRandom;
    }
    pNode = pNode->next;
  }

  return pNewHead;

}

void cloneListMain()
{
  Node *p1 = new Node('A');
  Node *p2 = new Node('B');
  Node *p3 = new Node('C');
  Node *p4 = new Node('D');
  Node *p5 = new Node('E');

  p1->next = p2;
  p2->next = p3;
  p3->next = p4;
  p4->next = p5;
  
  p2->random = p1;
  p1->random = p3;
  p3->random = p5;

  Node * pNew = cloneList(p1);

}