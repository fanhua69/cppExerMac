
#include <vector>
#include <iostream>
using namespace std;

bool checkHasRoot(vector<vector<int>> &g, int i, int j, vector<vector<int>> &checked)
{
    if ( g.size() < 1 || g[0].size() < 1 )
    {
        return false;
    }

    if ( i < 0 || i >= g.size() || j < 0 || j >= g[0].size() )
    {
        return false;
    }

    if ( g[i][j] == 0 )
    {
        return false;
    }

    if ( i == 0 )
    {
        return true;
    }

    if ( checked[i][j] )
    {
        return false;
    }

    checked[i][j] = true;

    return  checkHasRoot(g, i - 1, j, checked) ||
        checkHasRoot(g, i, j - 1, checked) ||
        checkHasRoot(g, i, j + 1, checked) ||
        checkHasRoot(g, i + 1, j, checked);
}


int countAllDropped(vector<vector<int>> &g, vector<vector<int>> &d)
{
    int allBricks = 0;
    for ( int i = 0; i < d.size(); i++ )
    {
        for ( int j = 0; j < d[0].size(); j++ )
        {
            if ( d[i][j] == 1 )
            {
                allBricks++;
                g[i][j] = 0;
            }
        }
    }

    return allBricks;
}



void getGridsInBlock(vector<vector<int>> &g, int i, int j, vector<vector<int>> &block)
{
    if ( g.size() == 0 || g[0].size() == 0 || i < 0 || i >= g.size() || j < 0 || j >= g[0].size() )
    {
        return;
    }

    if ( g[i][j] == 0 )
    {
        return;
    }

    if ( block[i][j] == 1 )
    {
        return;
    }

    block[i][j] = 1;

    getGridsInBlock(g, i, j - 1, block);
    getGridsInBlock(g, i, j + 1, block);
    getGridsInBlock(g, i - 1, j, block);
    getGridsInBlock(g, i + 1, j, block);
}

bool isBrickValid(vector<vector<int>> &g, int i, int j)
{
    if ( g.size() == 0 || g[0].size() == 0 || i < 0 || i >= g.size() || j < 0 || j >= g[0].size() )
    {
        return false;
    }

    return g[i][j] == 1 ;
}

void clearMarks(vector<vector<int>> &m)
{
    for(auto &i : m)
    {
        for(auto &j : i)
        {
            j = 0;
        }
    }
}

int checkDropGrid(vector<vector<int>> &g,vector<int> &hit)
{
    int i=hit[0];
    int j=hit[1];

    g[i][j]=0;

    vector<vector<int>> drops(g.size(),vector<int>(g[0].size(),0));

    vector<vector<int>> checked(g.size(), vector<int>(g[0].size(), 0));

    if( isBrickValid(g,i-1,j) && !checkHasRoot(g, i-1,j, checked))
    {
        getGridsInBlock(g,i-1,j,drops);
   }
    clearMarks(checked);


    if ( isBrickValid(g, i +1, j) && !checkHasRoot(g, i + 1, j, checked) )
    {
        getGridsInBlock(g, i +1, j, drops);
    }
    clearMarks(checked);


    if ( isBrickValid(g, i, j-1) && !checkHasRoot(g, i , j-1, checked) )
    {
        getGridsInBlock(g, i, j-1, drops);
    }
    clearMarks(checked);


    if ( isBrickValid(g, i , j+1) && !checkHasRoot(g, i, j+1, checked) )
    {
        getGridsInBlock(g, i , j+1, drops);
    }
    clearMarks(checked);


    return countAllDropped(g, drops);
}

vector<int> checkDropGrid(vector<vector<int>> &g, vector<vector<int>> &hits)
{
    vector<int> r;
    for(auto i : hits)
    {
        r.push_back(checkDropGrid(g,i));
    }

    return r;
}

void checkDropGridMain()
{
    //vector<vector<int>> grid={{1,0,0,0},{1,1,0,0}};
    //vector<vector<int>> hits={{1,1},{1,0}};

    //vector<int> r= checkDropGrid(grid,hits);

    //for(auto i : r)
    //{
    //    cout << i << endl;
    //}

    //cout << endl;

    vector<vector<int>> grid2 = {{0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    vector<vector<int>> hits2 = {
    {6, 0}, 
    {1, 0}, 
    {4, 3}, 
    {1, 2}, 
    {7, 1}, 
    {6, 3}, 
    {5, 2}, 
    {5, 1}, 
    {2, 4}, 
    {4, 4}, 
    {7, 3}
    };


    vector<int> r = checkDropGrid(grid2, hits2);

    for ( auto i : r )
    {
        cout << i << endl;
    }


}

