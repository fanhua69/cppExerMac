
#include <list>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

class LCW
{
public:
    LCW(int limit)
    {
        m_nLimit = limit;
    }

    int get(int key);
    void put(int key,int value);

    list<pair<int,int>> m_cache;
    std::map <int,list<pair<int,int>>::iterator> m_map;
    int m_nLimit;
};

void LCW::put(int key, int value)
{
    while(m_cache.size()>m_nLimit-1)
    {
        auto n = m_cache.back();
        m_map.erase(n.first);
        m_cache.pop_back();
    }

    m_cache.push_front({key,value});
    m_map[key]=m_cache.begin();
}

int LCW::get(int key)
{
    if(m_map.find(key) == m_map.end())
    {
        return -1;
    }

    auto it = m_map[key];

    m_cache.splice(m_cache.begin(),m_cache,it);

    return it->second;
}

void printLCW(LCW& l)
{
    for(auto i: l.m_cache)
    {
        cout << i.first << " "<< i.second << endl;
    }
    cout << endl;
}

void LCWMain()
{
    LCW lcw(3);
    lcw.put(1,1);
    lcw.put(2, 2);
    lcw.put(3, 3);

    printLCW(lcw);

    lcw.put(4,4);

    printLCW(lcw);

    cout << lcw.get(1);

}