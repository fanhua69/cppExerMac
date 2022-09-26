

#include <stdio.h>

#define nQueenQty 8

int nRowOrder[nQueenQty + 1];

bool chechGood(int nCurrentCol)
{
  int k;
  bool bColGood = true;
  for ( k = 1; k < nCurrentCol; k++ )  // Check if queens are in one line;
  {
    if ( nRowOrder[k] == nRowOrder[nCurrentCol] )
    {
      bColGood = false;
      break;
    }
  }

  if ( bColGood )
  {
    for ( k = 1; k < nCurrentCol; k++ )      // Check if multi queens are in diagonal 
    {
      if ( (nRowOrder[nCurrentCol] == nRowOrder[k] - (k - nCurrentCol)) || nRowOrder[nCurrentCol] == nRowOrder[k] + (k - nCurrentCol) )
      {
        bColGood = false;
        break;
      }
    }
  }

  return bColGood;
}

int EightQueens()
{
  int nCurrentCol, k, nGoodCount = 0;
  bool bFinishedSearching = false;
  bool bColGood = false;
  

  // Processing element i:
  nCurrentCol = 1;
  nRowOrder[nCurrentCol] = 1;
  printf("The possible configuration of 8 queens are :\n");

  while ( !bFinishedSearching )
  {
    while ( !bFinishedSearching && nCurrentCol <= nQueenQty )
    {
      bool bColGood = chechGood(nCurrentCol);

      if(bColGood) // column is good;
      {
        nCurrentCol++;

        if ( nCurrentCol <= nQueenQty )
        {
          if ( nRowOrder[nCurrentCol - 1] == nQueenQty )
          {
            nRowOrder[nCurrentCol] = 1;
          }
          else
          {
            nRowOrder[nCurrentCol] = nRowOrder[nCurrentCol - 1] + 1;
          }
        }
      }

      else // Column not good;
      {
        if ( nRowOrder[nCurrentCol] != nRowOrder[nCurrentCol - 1] ) // Searching the column is not ended yet;
        {
          if ( nRowOrder[nCurrentCol] == nQueenQty )
          {
            nRowOrder[nCurrentCol] = 1;
          }
          else
          {
            nRowOrder[nCurrentCol] ++;
          }
        }

        else  // Searching the column is end, retreat to previous column;
        {
          nCurrentCol--;

          if( nRowOrder[nCurrentCol] == nQueenQty )
          {
            if ( nCurrentCol == 1)
            {
              bFinishedSearching = true;
            }
            else if ( nCurrentCol > 1)
            {
              nRowOrder[nCurrentCol] = 1;
            }
          }
          else
          {
            nRowOrder[nCurrentCol]++;
          }
        }
      }
    }

    if ( !bFinishedSearching )
    {
      nGoodCount++;

      printf((nGoodCount - 1) % 3 ? " [%2d]: " : " \n[%2d]: ", nGoodCount);

      for ( k = 1; k <= nQueenQty; k++ )
      {
        printf(" %d", nRowOrder[k]);
      }

      if ( nRowOrder[nQueenQty - 1] < nQueenQty )
      {
        nRowOrder[nQueenQty - 1]++;
      }
      else
      {
        nRowOrder[nQueenQty - 1] = 1;
      }

      nCurrentCol = nQueenQty - 1;
    }
  }

  return 0;
}

