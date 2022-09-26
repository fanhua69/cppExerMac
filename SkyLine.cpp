

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Point
{
public:
    int x;
    mutable int y;

    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    bool operator < (const Point &o) const
    {
        return x < o.x;
    }
    bool operator == (const Point &o) const
    {
        return x == o.x;
    }
};


class Building
{

public:
    int left;
    int right;
    int height;

    virtual bool operator < (const Building &o) const
    {
        return left < o.left;
    };
};

class BuildingLeft : public Building
{
public:
    BuildingLeft(int l, int r, int h)
    {
        left = l;
        right = r;
        height = h;
    }

    virtual bool operator < (const Building &o) const override
    {
        return right < o.right;
    }
};

class BuildingRight : public Building
{
public:
    BuildingRight(int l, int r, int h)
    {
        left = l;
        right = r;
        height = h;
    }

    virtual bool operator < (const Building &o) const override
    {
        return left < o.left;
    }
};


vector<vector<int>> getSkyline(vector<vector<int>> &buildinglines)
{
    set<Point> allX;
    vector<BuildingRight> rightBuildings;
    for(auto a: buildinglines)
    {
        allX.insert({ a[0] - 1,0 });
        allX.insert({ a[0],a[2] });
        allX.insert({ a[1],a[2] });
        allX.insert({ a[1] + 1,0 });

        rightBuildings.emplace_back(a[0],a[1],a[2]);
    }

    sort(rightBuildings.begin(),rightBuildings.end());

    std::vector<BuildingLeft> leftBuildings;
    std::make_heap(leftBuildings.begin(), leftBuildings.end());
    
    for(auto &i : allX)
    {
        int x = i.x;

        // decrease the left buildings:
        while( leftBuildings.size()>0 && leftBuildings.front().right < x)
        {
            std::pop_heap(leftBuildings.begin(), leftBuildings.end());
            leftBuildings.erase(leftBuildings.end()-1);
        }

        // 
        while( rightBuildings.size()>0 && rightBuildings[0].left <= x)
        {
            leftBuildings.emplace_back(rightBuildings[0].left, rightBuildings[0].right, rightBuildings[0].height);
            push_heap(leftBuildings.begin(), leftBuildings.end());
            rightBuildings.erase(rightBuildings.begin());
        }

        for(auto a:leftBuildings)
        {
            if(x >= a.left && x<=a.right)
            {
                if(a.height>i.y)
                {
                    i.y = a.height;
                }
            }
        }
    }

    vector<vector<int>> a;
    if ( allX.begin()->y > 0 )
    {
        a.push_back({ allX.begin()->x,allX.begin()->y});
    }

    set<Point>::iterator i = allX.begin();
    auto ip=i;
    for ( ;i!=allX.end();i++)
    {
        if ( i->y > ip->y )
        {
            a.push_back({i->x,i->y});
        }
        else if ( i->y < ip->y )
        {
            a.push_back({ip->x,i->y});
        }
        ip=i;
    }

    return a;
}

void getSlyLineMain()
{
    vector<vector<int>> getSkyline(vector<vector<int>> &buildinglines);
    vector<vector<int>> b;
    b.push_back({2,9,10});
    b.push_back({3,7,15});
    b.push_back({5,12,12});
    b.push_back({15,20,10});
    b.push_back({19,24,8});

    vector<vector<int>> a = getSkyline(b);

    for(auto &i : a)
    {
        cout << i[0]<< " " << i[1]<< endl;
    }
}