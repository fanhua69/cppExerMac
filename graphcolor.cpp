//图着色问题回溯法

#include<stdio.h>


//int c[100][100];
bool ok(int vertexNum,
        int edges[][100],
        int g_color[100])//判断顶点k的着色是否发生冲突
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
    g_color[i] = 0;//初始化
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
        g_color[iVertexOrder] = g_color[iVertexOrder] + 1;//搜索下一个颜色
    }

    if ( g_color[iVertexOrder] <= nColorAvailable && iVertexOrder == nVertexQty )//求解完毕，输出解
    {
      for ( i = 1; i <= nVertexQty; i++ )
      {
        printf("%d ", g_color[i]);
      }
      printf("\n");
                                                        //return;//return表示之求解其中一种解
    }
    else if ( g_color[iVertexOrder] <= nColorAvailable && iVertexOrder < nVertexQty )
    {
      iVertexOrder = iVertexOrder + 1;    //处理下一个顶点
    }
    else
    {
      g_color[iVertexOrder] = 0;
      iVertexOrder = iVertexOrder - 1;//回溯
    }
  }
}

/*
无向图邻接矩阵示例
0 1 1 0 0
0 1 1 0 1
1 1 0 0 1
0 1 0 0 1
0 1 1 1 0
*/
void graphcolorMain()
{
  int i, j, nVertexQty, nColorAvailable;
  
  //存储n个顶点的无向图的数组
  int realMatrixEdges[5][5] = { 0, 1, 1, 0, 0,
    0, 1, 1, 0, 1,
    1, 1, 0, 0, 1,
    0, 1, 0, 0, 1,
    0, 1, 1, 1, 0};

  int matrixEdges[100][100];

  printf("输入顶点数n和着色数m:\n");
  //scanf("%d %d", &nVertexQty, &nColorAvailable);
  nVertexQty = 5;
  nColorAvailable = 3;

  printf("输入无向图的邻接矩阵:\n");
  for ( i = 1; i <= nVertexQty; i++ )
    for ( j = 1; j <= nVertexQty; j++ )
      matrixEdges[i][j] = realMatrixEdges[i][j];

  

  printf("着色所有可能的解:\n");
  graphcolor(nVertexQty, nColorAvailable, matrixEdges);
}