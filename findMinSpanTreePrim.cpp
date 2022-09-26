

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <utility>

using namespace std;

namespace PRIM
{
    class Route
    {
    public:
        string  nameTo;
        int     weight;
    };
    class Vertex
    {
    public:
        Vertex(string n)
        {
            name = n;
            key = INT_MAX;
            parant = "";
        }

        void addRoute(string name, int weight)
        {
            m_routes.push_back(Route({name,weight}));
        }

        string  name;
        int     key;
        string  parant;
        vector<Route> m_routes;
    };

    class Graph
    {
    public:
        void addVertex(string name)
        {
            if(m_mapVertices[name] == nullptr)
            {
                m_vertices.push_back(make_shared<Vertex>(name));
                m_mapVertices[name]=m_vertices.back();
            }
        }

        void addRoute(string f, string t, int w)
        {
            addVertex(f);
            addVertex(t);
            m_mapVertices[f]->addRoute(t,w);
            m_mapVertices[t]->addRoute(f, w);
        }
        vector<shared_ptr<Vertex>> m_vertices;
        map<string, shared_ptr<Vertex>> m_mapVertices;

        vector<pair<string, string>>  findPrimMSP();
    };

    vector<pair<string, string>>  Graph::findPrimMSP()
    {
        vector<pair<string, string>> msp;

        if ( m_vertices.size() == 0 )
        {
            return msp;
        }
        shared_ptr<Vertex> v = m_vertices[0];
        v->key = 0;

        while ( m_vertices.size() > 0 )
        {
            auto vi = std::min_element(m_vertices.begin(), m_vertices.end(), [](shared_ptr<Vertex> x, shared_ptr<Vertex> y)
            {
                return x->key < y->key;
            });

            shared_ptr<Vertex> v = *vi;
            if ( v->parant != "" )
            {
                msp.push_back(make_pair(v->parant, v->name));
            }

            for ( Route r : v->m_routes)
            {
                shared_ptr<Vertex> tv = m_mapVertices[r.nameTo];
                if ( tv->key > r.weight)
                {
                    tv->key = r.weight;
                    tv->parant = v->name;
                }
            }
                
            m_vertices.erase(remove(m_vertices.begin(),m_vertices.end(), v),m_vertices.end());
        }

        return msp;
    }
    
}


using namespace PRIM;

void findMinSpanTreePrimMain()
{
    vector<char> a = {'a','b','c','d','e','b'};
    a.erase(std::remove(a.begin(),a.end(),'b'),a.end());
    
    for(auto c : a)
    {
        cout << c << endl;
    }

    Graph g;

    g.addRoute("a", "b", 4);
    g.addRoute("a", "f", 2);
    g.addRoute("b", "c", 6);
    g.addRoute("c", "d", 3);
    g.addRoute("c", "f", 1);
    g.addRoute("d", "e", 2);
    g.addRoute("e", "f", 4);
    g.addRoute("b", "f", 3);

    vector<pair<string, string>>  m = g.findPrimMSP();
    for(auto a : m)
    {
        cout << a.first << " " << a.second << endl;
    }


}