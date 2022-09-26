#include "mylist.h"

bool hasLoop(CMyListNode *startNode)
{
    CMyListNode *preNode = NULL;
    CMyListNode *currentNode = startNode;
    CMyListNode *nextNode;

    if(!currentNode->next())
        return false;

    while(currentNode)
    {
        nextNode = currentNode->next();
        currentNode->setNext(preNode);
        preNode = currentNode;
        currentNode = nextNode;
    }

    return preNode == startNode;
}

void listCheckCycleReverseMain()
{
    CMyListNode *p1 = new CMyListNode(1);
    CMyListNode *p2 = new CMyListNode(2);
    CMyListNode *p3 = new CMyListNode(3);
    CMyListNode *p4 = new CMyListNode(4);
    CMyListNode *p5 = new CMyListNode(5);

    p1->append(p2);
    p2->append(p3);
    p3->append(p4);
    p4->append(p5);
    p5->setNext(p3);

    hasLoop (p1);
}