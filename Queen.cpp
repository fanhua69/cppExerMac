

#include <vector>

#include <iostream>

using namespace std;


void printBoard(vector<vector<char>> &board);


bool checkAttack(vector<vector<char>> &board, int r, int c)
{
    int N = board.size();

    int nj = 0;
    for (int i = 0; i <= r; i++ )
    {
        if ( board[i][c] == 'Q' )
        {
            nj++;
            if ( nj > 1 )
            {
                return false;
            }
        }
    }

    int nc1 = 0;
    for(int s=-N;s<=0;s++)
    {
        int i=r+s;
        int j=c+s;
        if(i>=0 && i<=r  && j>=0 && j<N)
        {
            if (board[i][j]=='Q')
            {
                nc1++;
                if(nc1>1)
                {
                    return false;
                }
            }
        }
    }

    nc1 = 0;
    for ( int s = -N; s <= 0; s++ )
    {
        int i = r + s;
        int j = c - s;
        if ( i >= 0 && i <=r && j >= 0 && j < N )
        {
            if ( board[i][j] == 'Q' )
            {
                nc1++;
                if ( nc1 > 1 )
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Queen( vector<vector<char>> &board, int order, vector<vector<vector<char>>> &allboards)
{
    int N = board.size();
    if(order >= N)
    {
        return true;
    }

    for(int i=0;i<N;i++)
    {
        board[order][i] = 'Q';
        if(checkAttack(board,order,i))
        {
            if(Queen(board,order+1,allboards))
            {
                if(std::find(allboards.begin(),allboards.end(),board)== allboards.end())
                {
                    allboards.push_back(board);
                }
                cout << ".";
            }
        }
        board[order][i]='.';
    }

    return false;
}

void Queen(int N)
{
    vector<vector<char>> b(N,vector<char>(N,'.'));

    vector<vector<vector<char>>> allboards;
    Queen(b,0, allboards);

    for(int i=0;i<allboards.size();i++)
    {
        vector<vector<char>> &b = allboards[i];
        printBoard(b);
    }
}

void QueenMain()
{
    Queen(5);
}