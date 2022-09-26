

//
// There is a MxN matrix.The matrix elements are either 1 or 0.
// If it is 1, it is passable.
// If it is 0, it is blocked.
// Write a function to find number of routes from(0, 0) to(M - 1, N - 1).
//

#define COL_QTY 3

int findRouteOfMatrix(int matrix[][COL_QTY], int m, int iStartRow, int iStartCol)
{
  int nRouteToNextRow = 0;
  int nRouteToNextCol = 0;

  if(iStartRow == m - 1 && iStartCol == COL_QTY-2)
  {
    if(matrix[m-1][COL_QTY-1] != 0)
    {
      return 1;
    }
  }

  if ( iStartCol == COL_QTY - 1 && iStartRow == m - 2 )
  {
    if ( matrix[m - 1][COL_QTY - 1] != 0 )
    {
      return 1;
    }
  }

  if( iStartRow < m - 1 && matrix[iStartRow+1][iStartCol] != 0)
  {
    nRouteToNextRow = findRouteOfMatrix(matrix,m,iStartRow+1,iStartCol);
  }

  if( iStartCol < COL_QTY - 1 && matrix[iStartRow ][iStartCol+1] != 0 )
  {
    nRouteToNextCol = findRouteOfMatrix(matrix, m, iStartRow , iStartCol+1);
  }

  return nRouteToNextRow + nRouteToNextCol;
}

void findRouteOfMatrixMain()
{
  int matrix[3][COL_QTY]={1,1,1,1,1,1,1,1,1};
  int n = findRouteOfMatrix(matrix,3,0,0);
}