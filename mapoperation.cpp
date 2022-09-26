

#include <map>
#include <limits>
#include <stdio.h>
#include <iostream>

using namespace std;

template<typename K, typename V>
class interval_map
{
    std::map<K, V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map(V const& val)
    {
        m_map.insert(m_map.end(), std::make_pair(std::numeric_limits<K>::lowest(), val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign(K const& keyBegin, K const& keyEnd, V const& val)
    {
        if ( keyBegin < keyEnd )
        {
            // find the positions that are behind the begin and end node:
            typename std::map<K, V>::iterator itBegin = m_map.lower_bound(keyBegin);
            typename std::map<K, V>::iterator itEnd   = m_map.upper_bound(keyEnd);

            // Insert a node at the keyEnd with a value of the previous node:
            if(itEnd != m_map.begin())
            {
                typename std::map<K, V>::iterator itPre = itEnd;
                if(!((--itPre)->second == val))
                {
                    itEnd = m_map.insert(itEnd, std::make_pair(keyEnd, itPre->second));
                }
            }

            // Delete nodes that are between the keyBegin and keyEnd:
            typename std::map<K, V>::iterator itBackup;
            while( itBegin != m_map.end() && itBegin ->first < itEnd ->first )
            {
                itBackup = itBegin;
                itBegin++;
                m_map.erase(itBackup);
            }

            // Insert a node for the keyBegin:
            if ( itEnd != m_map.begin() )
            {
                typename std::map<K, V>::iterator itPre = itEnd;
                if ( !((--itPre)->second == val) )
                {
                    itEnd = m_map.insert(itEnd, std::make_pair(keyBegin, val));
                }
            }
        }
    }

    // look-up of the value associated with key
    V const& operator[](K const& key) const
    {
        return (--m_map.upper_bound(key))->second;
    }

    void print()
    {
        std::map<K, V>::iterator it = m_map.begin();
        while(it != m_map.end())
        {
            K k = it->first;
            std::cout << k() << ";" << (it ->second )()<< endl;
            it++;
        }
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of unsigned int intervals to char.


class MyKey
{
public:
    bool operator < (const MyKey &o) const 
    {
        return m_key < o.m_key;
    }

    bool operator == (const MyKey &o) const
    {
        return m_key == o.m_key;
    }

    bool operator > (const MyKey &o) const
    {
        return m_key > o.m_key;
    }

    MyKey()
    {
        m_key = -9999;//std::numeric_limits<int>::lowest();
    }

    MyKey (int n)
    {
        m_key = n;
    }

    int operator()()
    {
        return m_key;
    }

    int m_key;
};

class MyValue
{
public:
    MyValue(char c)
    {
        m_value = c;
    }

    bool operator < (const MyValue &o) const
    {
        return m_value < o.m_value;
    }

    bool operator == (const MyValue &o) const
    {
        return m_value == o.m_value;
    }

    char operator ()()
    {
        return m_value;
    }
    char m_value;
};


void interval_map_main()
{
    interval_map<MyKey, MyValue> mm('@');
    mm.assign(MyKey(10), MyKey(20), MyValue('a'));
    mm.assign(MyKey(20), MyKey(30), MyValue('b'));
    mm.assign(MyKey(30), MyKey(40), MyValue('c'));
    mm.assign(MyKey(25), MyKey(27), MyValue('X'));

    mm.print();

}