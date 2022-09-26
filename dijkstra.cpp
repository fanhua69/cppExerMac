

/***************************************
* About:    有向图的Dijkstra算法实现
* Author:   Tanky Woo
* Blog:     www.WuTianQi.com
***************************************/

#include <iostream>
using namespace std;

const int MAX_NODE_NUM  = 100;
const int MAX_INT       = 999999;

// n -- n nodes
// v -- the source node
// dist[] -- the distance from the ith node to the source node
// prev[] -- the previous node of the ith node
// c[][] -- every two nodes' distance
void Dijkstra(int  nNodeQty, 
              int  iSrcNode, 
              int *nDistToSrcNode, 
              int *iPrevNode, 
              int  nDistance[MAX_NODE_NUM][MAX_NODE_NUM])
{
  bool bIsInS[MAX_NODE_NUM];    // 判断是否已存入该点到S集合中

  // Get the nodes whose previous node is Src node:
  for ( int i = 1; i <= nNodeQty; ++i )
  {
    nDistToSrcNode[i] = nDistance[iSrcNode][i];
    bIsInS[i] = 0;     // 初始都未用过该点
    if ( nDistToSrcNode[i] == MAX_INT )
      iPrevNode[i] = 0;
    else
      iPrevNode[i] = iSrcNode;
  }

  // Add the source node to S:
  nDistToSrcNode[iSrcNode] = 0;
  bIsInS[iSrcNode] = 1;

  // 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
  // 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
  // 注意是从第二个节点开始，第一个为源点
  for ( int i = 2; i <= nNodeQty; ++i ) // while there are still nodes that are not in S
  {
    int nMinDistToSrcNode = MAX_INT;
    int iNodeMinDistToSrc = iSrcNode;

    // 找出当前未使用的点j的dist[j]最小值
    for ( int j = 1; j <= nNodeQty; ++j )
    {
      if ( (!bIsInS[j]) && nDistToSrcNode[j] < nMinDistToSrcNode )
      {
        iNodeMinDistToSrc = j;              // u保存当前邻接点中距离最小的点的号码
        nMinDistToSrcNode = nDistToSrcNode[j];
      }
    }

    bIsInS[iNodeMinDistToSrc] = 1;    // 表示u点已存入S集合中

    // 更新dist
    for ( int j = 1; j <= nNodeQty; ++j )
    {
      if ( (!bIsInS[j]) && nDistance[iNodeMinDistToSrc][j] < MAX_INT )
      {
        int nNewDist = nDistToSrcNode[iNodeMinDistToSrc] + nDistance[iNodeMinDistToSrc][j];
        if ( nNewDist < nDistToSrcNode[j] )
        {
          nDistToSrcNode[j] = nNewDist;
          iPrevNode[j] = iNodeMinDistToSrc;
        }
      }
    }
  }
}



// 查找从源点v到终点u的路径，并输出
void searchPath(int *iPrevNodeOfCurrNode,
                int iSrcNode, 
                int iTargetNode)
{
  int iRouteNodes[MAX_NODE_NUM];
  
  int nNodeQty = 1;
  iRouteNodes[nNodeQty] = iTargetNode;
  nNodeQty++;

  int iPrevNode = iPrevNodeOfCurrNode[iTargetNode];
  while ( iPrevNode != iSrcNode )
  {
    iRouteNodes[nNodeQty] = iPrevNode;
    nNodeQty++;
    iPrevNode = iPrevNodeOfCurrNode[iPrevNode];
  }

  iRouteNodes[nNodeQty] = iSrcNode;
  for ( int i = nNodeQty; i >= 1; --i )
  {
    if ( i != 1 )
      cout << iRouteNodes[i] << " -> ";
    else
      cout << iRouteNodes[i] << endl;
  }
}

/*
输入数据:
5
7
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
输出数据:
999999 10 999999 30 100
10 999999 50 999999 999999
999999 50 999999 20 10
30 999999 20 999999 60
100 999999 10 60 999999
源点到最后一个顶点的最短路径长度: 60
源点到最后一个顶点的路径为: 1 -> 4 -> 3 -> 5

最后给出两道题目练手，都是直接套用模版就OK的：
1.HDOJ 1874 畅通工程续
http://www.wutianqi.com/?p=1894

2.HDOJ 2544 最短路
http://www.wutianqi.com/?p=1892
*/

int dijkstraMain()
{
  // 各数组都从下标1开始
  int gdMinDistToSrc[MAX_NODE_NUM];               // 表示当前点到源点的最短路径长度
  int giPrevNodeOfCurrNode[MAX_NODE_NUM];         // 记录当前点的前一个结点
  int gnDistOfNodes[MAX_NODE_NUM][MAX_NODE_NUM];  // 记录图的两点间路径长度
  int gnNodeQty, gnRouteQty;                      // 图的结点数和路径数

  // 各数组都从下标1开始

  // 输入结点数
  gnNodeQty = 4;
  // 输入路径数
  gnRouteQty = 4;

  // 初始化c[][]为maxint
  for ( int i = 1; i <= gnNodeQty; ++i )
  {
    for ( int j = 1; j <= gnNodeQty; ++j )
    {
      gnDistOfNodes[i][j] = MAX_INT;
    }
  }

  int array[]={1,2,10,1,3,20,2,4,90,3,4,50};

  int n= 0;
  for ( int i = 1; i <= gnRouteQty; ++i )
  {
    int p=array[n];n++;
    int q = array[n]; n++;
    int len = array[n]; n++;

    if ( len < gnDistOfNodes[p][q] )       // 有重边
    {
      gnDistOfNodes[p][q] = len;      // p指向q
      gnDistOfNodes[q][p] = len;      // q指向p，这样表示无向图
    }
  }

  for ( int i = 1; i <= gnNodeQty; ++i )
  {
    gdMinDistToSrc[i] = MAX_INT;
  }

  for ( int i = 1; i <= gnNodeQty; ++i )
  {
    for ( int j = 1; j <= gnNodeQty; ++j )
    {
      printf("%8d", gnDistOfNodes[i][j]);
    }
    printf("\n");
  }

  Dijkstra(gnNodeQty, 1, gdMinDistToSrc, giPrevNodeOfCurrNode, gnDistOfNodes);

  // 最短路径长度
  cout << "源点到最后一个顶点的最短路径长度: " << gdMinDistToSrc[gnNodeQty] << endl;

  // 路径
  cout << "源点到最后一个顶点的路径为: ";
  searchPath(giPrevNodeOfCurrNode, 1, gnNodeQty);

  return 0;
}