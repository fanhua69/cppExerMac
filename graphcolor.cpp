//ͼ��ɫ������ݷ�

#include<stdio.h>


//int c[100][100];
bool ok(int vertexNum,
        int edges[][100],
        int g_color[100])//�ж϶���k����ɫ�Ƿ�����ͻ
{
  int i;
  for ( i = 1; i < vertexNum; i++ )
  {
    if ( edges[vertexNum][i] == 1 && g_color[i] == g_color[vertexNum] )
    {
      return false;
    }
  }
  return true;
}

void graphcolor(int nVertexQty, 
                int nColorAvailable, 
                int edges[][100])
{
  int g_color[100];

  int i, iVertexOrder;
  for ( i = 1; i <= nVertexQty; i++ )
  {
    g_color[i] = 0;//��ʼ��
  }

  iVertexOrder = 1;
  while ( iVertexOrder >= 1 )
  {
    g_color[iVertexOrder] = g_color[iVertexOrder] + 1;
    while ( g_color[iVertexOrder] <= nColorAvailable )
    {
      if ( ok(iVertexOrder, edges,g_color) )
        break;
      else 
        g_color[iVertexOrder] = g_color[iVertexOrder] + 1;//������һ����ɫ
    }

    if ( g_color[iVertexOrder] <= nColorAvailable && iVertexOrder == nVertexQty )//�����ϣ������
    {
      for ( i = 1; i <= nVertexQty; i++ )
      {
        printf("%d ", g_color[i]);
      }
      printf("\n");
                                                        //return;//return��ʾ֮�������һ�ֽ�
    }
    else if ( g_color[iVertexOrder] <= nColorAvailable && iVertexOrder < nVertexQty )
    {
      iVertexOrder = iVertexOrder + 1;    //������һ������
    }
    else
    {
      g_color[iVertexOrder] = 0;
      iVertexOrder = iVertexOrder - 1;//����
    }
  }
}

/*
����ͼ�ڽӾ���ʾ��
0 1 1 0 0
0 1 1 0 1
1 1 0 0 1
0 1 0 0 1
0 1 1 1 0
*/
void graphcolorMain()
{
  int i, j, nVertexQty, nColorAvailable;
  
  //�洢n�����������ͼ������
  int realMatrixEdges[5][5] = { 0, 1, 1, 0, 0,
    0, 1, 1, 0, 1,
    1, 1, 0, 0, 1,
    0, 1, 0, 0, 1,
    0, 1, 1, 1, 0};

  int matrixEdges[100][100];

  printf("���붥����n����ɫ��m:\n");
  //scanf("%d %d", &nVertexQty, &nColorAvailable);
  nVertexQty = 5;
  nColorAvailable = 3;

  printf("��������ͼ���ڽӾ���:\n");
  for ( i = 1; i <= nVertexQty; i++ )
    for ( j = 1; j <= nVertexQty; j++ )
      matrixEdges[i][j] = realMatrixEdges[i][j];

  

  printf("��ɫ���п��ܵĽ�:\n");
  graphcolor(nVertexQty, nColorAvailable, matrixEdges);
}