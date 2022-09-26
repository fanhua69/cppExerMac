

#include "mylist.h"

CMyListNode * findStartCycle(CMyListNode *startNode)
{
    bool cycleFound = false;
    CMyListNode *slowNode = startNode;
    CMyListNode *fastNode = startNode;
    while(fastNode->next() && fastNode ->next()->next())
    {
        slowNode = slowNode->next();
        fastNode = fastNode->next()->next();
        if(slowNode == fastNode)
        {
            cycleFound = true;
            break;
        }
    }

    if(!cycleFound)
    {
        return false;
    }
    else
    {
        slowNode = startNode;
        while(true)
        {
            slowNode = slowNode->next();
            fastNode = fastNode->next();
            if(slowNode == fastNode)
            {
                break;
            }
        }

        return slowNode;
    }
}


void listFindStartCycleMain()
{
    CMyListNode *p1 = new CMyListNode(1);
    CMyListNode *p2 = new CMyListNode(2);
    CMyListNode *p3 = new CMyListNode(3);
    CMyListNode *p4 = new CMyListNode(4);
    CMyListNode *p5 = new CMyListNode(5);
    CMyListNode *p6 = new CMyListNode(6);
    CMyListNode *p7 = new CMyListNode(7);
    CMyListNode *p8 = new CMyListNode(8);
    CMyListNode *p9 = new CMyListNode(9);
    CMyListNode *p10= new CMyListNode(10);

    p1->append(p2);
    p2->append(p3);
    p3->append(p4);
    p4->append(p5);
    p5->append(p6);
    p6->append(p7);
    p7->append(p8);
    p8->append(p9);
    p9->append(p10);
    p10->setNext(p7);

    findStartCycle(p1);
}