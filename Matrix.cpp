
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define WIDTH 9



vector<vector<char>> boardC;

char findNotIn(vector<char>& row, vector<char> &col, vector<char>&sbd, vector<char> &bad)
{
    for(int i=1;i<=9;i++)
    {
        char c = '0'+i;
        if(std::find(row.begin(), row.end(), c) == row.end() &&
           std::find(col.begin(), col.end(), c) == col.end() &&
           std::find(sbd.begin(), sbd.end(), c) == sbd.end() &&
           std::find(bad.begin(), bad.end(), c) == bad.end() )
        {
            return c;
        }
    }

    return '-';
}

void get3groups(vector<vector<char>> &board,
                int i, 
                int j, 
                vector<char> &row, 
                vector<char> &col, 
                vector<char> &smallBoard)
{
    for(int k=0;k<WIDTH;k++)
    {
        if(board[i][k]!='.')
        {
            row.push_back(board[i][k]);
        }
    }

    for(int k=0;k<WIDTH;k++)
    {
        if ( board[k][j] != '.' )
        {
            col.push_back(board[k][j]);
        }
    }

    int sr = i / 3 * 3;
    int er = sr + 2;
    int sc = j /3 *3;
    int ec = sc + 2;

    for(int m=sr;m <=er ;m++)
    {
        for(int n=sc;n<=ec;n++)
        {
            if(board[m][n] != '.')
            {
                smallBoard.push_back(board[m][n]);
            }
        }
    }

    return;
}

void printBoard(vector<vector<char>>&board)
{
    for ( int i = 0; i < board.size(); i++ )
    {
        for ( int j = 0; j < board[0].size(); j++ )
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl<< endl;
}

bool solveSudoku(vector<vector<char>>&board, int i, int j)
{
    if(i>= board.size() || j>=board[0].size())
    {
        return true;
    }

    vector<char> bads;

    char cc = board[i][j];
    while(true)
    {
        if(board[i][j] == '.')
        {
            vector <char> row, col, sbd;
            get3groups(board, i, j, row, col, sbd);
            char c = findNotIn(row, col, sbd, bads);
            if(c == '-')
            {
                return false;
            }

            board[i][j]= c;
            bads.push_back(c);
        }

        int in = i;
        int jn =j;

        jn++;
        if(jn>8)
        {
            jn=0;
            in++;
        }


        if( !solveSudoku(board, in , jn))
        {
            board[i][j] = cc;
            if ( cc != '.' )
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
}

void solveSudoku(vector<vector<char>>&board)
{
    solveSudoku(board,0,0);
}

void sudokuMain()
{
    boardC.push_back({ '5','3','4','6','7','8','9','1','2' });
    boardC.push_back({ '6','7','2','1','9','5','3','4','8' });
    boardC.push_back({ '1','9','8','3','4','2','5','6','7' });
    boardC.push_back({ '8','5','9','7','6','1','4','2','3' });
    boardC.push_back({ '4','2','6','8','5','3','7','9','1' });
    boardC.push_back({ '7','1','3','9','2','4','8','5','6' });
    boardC.push_back({ '9','6','1','5','3','7','2','8','4' });
    boardC.push_back({ '2','8','7','4','1','9','6','3','5' });
    boardC.push_back({ '3','4','5','2','8','6','1','7','9' });


    vector<vector<char>> board;
    board.push_back({ '5','3','.','.','7','.','.','.','.'});
    board.push_back({ '6','.','.','1','9','5','.','.','.'});
    board.push_back({ '.','9','8','.','.','.','.','6','.'});
    board.push_back({ '8','.','.','.','6','.','.','.','3'});
    board.push_back({ '4','.','.','8','.','3','.','.','1'});
    board.push_back({ '7','.','.','.','2','.','.','.','6'});
    board.push_back({ '.','6','.','.','.','.','2','8','.'});
    board.push_back({ '.','.','.','4','1','9','.','.','5'});
    board.push_back({ '.','.','.','.','8','.','.','7','9'});

    //board.push_back({ '5','3','.'});
    //board.push_back({ '6','.','.'});
    //board.push_back({ '.','9','8'});

    solveSudoku(board);

    printBoard(board);

}