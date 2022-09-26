

/***************************************
* About:    ����ͼ��Dijkstra�㷨ʵ��
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
  bool bIsInS[MAX_NODE_NUM];    // �ж��Ƿ��Ѵ���õ㵽S������

  // Get the nodes whose previous node is Src node:
  for ( int i = 1; i <= nNodeQty; ++i )
  {
    nDistToSrcNode[i] = nDistance[iSrcNode][i];
    bIsInS[i] = 0;     // ��ʼ��δ�ù��õ�
    if ( nDistToSrcNode[i] == MAX_INT )
      iPrevNode[i] = 0;
    else
      iPrevNode[i] = iSrcNode;
  }

  // Add the source node to S:
  nDistToSrcNode[iSrcNode] = 0;
  bIsInS[iSrcNode] = 1;

  // ���ν�δ����S���ϵĽ���У�ȡdist[]��Сֵ�Ľ�㣬������S��
  // һ��S����������V�ж��㣬dist�ͼ�¼�˴�Դ�㵽������������֮������·������
  // ע���Ǵӵڶ����ڵ㿪ʼ����һ��ΪԴ��
  for ( int i = 2; i <= nNodeQty; ++i ) // while there are still nodes that are not in S
  {
    int nMinDistToSrcNode = MAX_INT;
    int iNodeMinDistToSrc = iSrcNode;

    // �ҳ���ǰδʹ�õĵ�j��dist[j]��Сֵ
    for ( int j = 1; j <= nNodeQty; ++j )
    {
      if ( (!bIsInS[j]) && nDistToSrcNode[j] < nMinDistToSrcNode )
      {
        iNodeMinDistToSrc = j;              // u���浱ǰ�ڽӵ��о�����С�ĵ�ĺ���
        nMinDistToSrcNode = nDistToSrcNode[j];
      }
    }

    bIsInS[iNodeMinDistToSrc] = 1;    // ��ʾu���Ѵ���S������

    // ����dist
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



// ���Ҵ�Դ��v���յ�u��·���������
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
��������:
5
7
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
�������:
999999 10 999999 30 100
10 999999 50 999999 999999
999999 50 999999 20 10
30 999999 20 999999 60
100 999999 10 60 999999
Դ�㵽���һ����������·������: 60
Դ�㵽���һ�������·��Ϊ: 1 -> 4 -> 3 -> 5

������������Ŀ���֣�����ֱ������ģ���OK�ģ�
1.HDOJ 1874 ��ͨ������
http://www.wutianqi.com/?p=1894

2.HDOJ 2544 ���·
http://www.wutianqi.com/?p=1892
*/

int dijkstraMain()
{
  // �����鶼���±�1��ʼ
  int gdMinDistToSrc[MAX_NODE_NUM];               // ��ʾ��ǰ�㵽Դ������·������
  int giPrevNodeOfCurrNode[MAX_NODE_NUM];         // ��¼��ǰ���ǰһ�����
  int gnDistOfNodes[MAX_NODE_NUM][MAX_NODE_NUM];  // ��¼ͼ�������·������
  int gnNodeQty, gnRouteQty;                      // ͼ�Ľ������·����

  // �����鶼���±�1��ʼ

  // ��������
  gnNodeQty = 4;
  // ����·����
  gnRouteQty = 4;

  // ��ʼ��c[][]Ϊmaxint
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

    if ( len < gnDistOfNodes[p][q] )       // ���ر�
    {
      gnDistOfNodes[p][q] = len;      // pָ��q
      gnDistOfNodes[q][p] = len;      // qָ��p��������ʾ����ͼ
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

  // ���·������
  cout << "Դ�㵽���һ����������·������: " << gdMinDistToSrc[gnNodeQty] << endl;

  // ·��
  cout << "Դ�㵽���һ�������·��Ϊ: ";
  searchPath(giPrevNodeOfCurrNode, 1, gnNodeQty);

  return 0;
}