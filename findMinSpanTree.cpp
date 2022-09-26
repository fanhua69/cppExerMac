
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

namespace MST // minimum spanning tree
{
    
    template <class T>
    class DisjointSet
    {
    public:
        T & findSet(T &t)
        {
            if(m_parents[t] == t)
            {
                return t;
            }
            else
            {
                return findSet(m_parents[t]);
            }
        }

        void addElement(T t)
        {
            m_elements.push_back(t);
            m_parents[t] = t;
            m_children[t] = t;
            m_ranks[t] = 0;
        }

        void UnionSets( T &s1, T &s2)
        {
            if(m_ranks[s1]<m_ranks[s2])
            {
                m_parents[s1] = s2;

            }
            else if( m_ranks[s2]<m_ranks[s1] )
            {
                m_parents[s1] = s2;
            }
            else
            {
                m_parents[s1] = s2;
                m_ranks[s2] ++;
            }
        }

        vector<T>   m_elements;
        map<T,T>    m_parents;
        map<T,T>    m_children;
        map<T,int>  m_ranks;
    };

    class Vertex
    {
    public:
        Vertex(string name)
        {
            m_name = name;
        }

        bool operator == (const Vertex &o)
        {
            return m_name == o.m_name;
        }
        string m_name;
    };

    class Edge
    {
    public:
        Edge(string f, string t, int w)
        {
            m_nameFrom = f;
            m_nameTo = t;
            m_weight = w;
        }
        string m_nameFrom;
        string m_nameTo;
        int m_weight;
    };

    class Graph
    {
    public:
        vector<Vertex> m_vertices;
        vector<Edge> m_edges;
        DisjointSet <string> m_disjointSets;

        void addVertex(string name)
        {
            if(find(m_vertices.begin(),m_vertices.end(),Vertex(name))==m_vertices.end())
            {
                m_vertices.push_back(Vertex(name));
                m_disjointSets.addElement(name);
            }
        }

        void addEdge(Edge e)
        {
            addEdge(e.m_nameFrom,e.m_nameTo,e.m_weight);
        }

        void addEdge(string nameFrom, string nameTo,int weight)
        {
            addVertex(nameFrom);
            addVertex(nameTo);
            m_edges.push_back(Edge(nameFrom,nameTo,weight));
        }

        void findTheMST();
    };

    void Graph::findTheMST()
    {
        Graph mst;

        sort(m_edges.begin(),m_edges.end(),[](Edge x, Edge y){return x.m_weight < y.m_weight;});

        for(Edge e : m_edges)
        {
            string f = m_disjointSets.findSet(e.m_nameFrom);
            string t = m_disjointSets.findSet(e.m_nameTo);

            if(f != t)
            {
                mst.addEdge(e);
                m_disjointSets.UnionSets(f,t);
            }
        }

        for(Edge e : mst.m_edges)
        {
            cout << e.m_nameFrom << " " << e.m_nameTo << endl;
        }
    }
}

using namespace MST;


// Kruskal Method:
void findMSTMain()  
{
    
    Graph g;
    g.addEdge("a","b",4);
    g.addEdge("a", "f", 2);
    g.addEdge("b", "c", 6);
    g.addEdge("c", "d", 3);
    g.addEdge("c", "f", 1);
    g.addEdge("d", "e", 2);
    g.addEdge("e", "f", 4);

    g.findTheMST();
}
