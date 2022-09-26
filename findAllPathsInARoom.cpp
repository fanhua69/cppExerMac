#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <stack>

using namespace std;

typedef std::stack<std::pair<int, int>> roomPath;
typedef std::vector<roomPath> AllRoomPaths;
typedef std::vector<std::vector<int>> roomArray;

bool findallarraypaths(const roomArray &a, roomPath path, int i, int j, AllRoomPaths &paths)
{
    int row = a.size();
    if ( row < 1 )
    {
        return false;
    }

    int col = a[0].size();
    if ( col < 1 )
    {
        return false;
    }

    if ( i == row - 1 && j == col - 1 )
    {
        paths.push_back(path);
        return true;
    }


    if ( j < col - 1 )
    {
        j++;
        if ( a[i][j] == 1 )
        {
            path.push(std::make_pair(i, j));
            findallarraypaths(a, path, i, j,paths);
            path.pop();
        }
        j--;
        
    }

    if ( i < row - 1 )
    {
        i++;
        if ( a[i][j] == 1 )
        {
            path.push(std::make_pair(i, j));
            findallarraypaths(a, path, i, j,paths);
        }
    }

    return false;
}



int findallpathsinroom()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    roomArray room;
    std::vector<int> rowRoom1 = { 1,0,0,0,0 };
    std::vector<int> rowRoom2 = { 1,1,1,1,1 };
    std::vector<int> rowRoom3 = { 1,0,1,0,1 };
    std::vector<int> rowRoom4 = { 1,0,1,1,1 };
    std::vector<int> rowRoom5 = { 1,1,1,0,1 };
    room.push_back(rowRoom1);
    room.push_back(rowRoom2);
    room.push_back(rowRoom3);
    room.push_back(rowRoom4);
    room.push_back(rowRoom5);

    roomPath p;
    AllRoomPaths paths;

    int i = 0, j = 0;
    p.push(std::make_pair(i, j));
    findallarraypaths(room, p, i, j, paths);

    int pathorder = 0;
    for(auto p : paths)
    {
        pathorder++;
        cout << "Path:" << pathorder<<endl;
        while(p.size()>0)
        {
            std::pair<int, int> node = p.top();
            cout << node.first << "," << node.second << endl;
            p.pop();
        }
    }

    return 0;
}
