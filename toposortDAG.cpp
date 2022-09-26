

#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <string>

namespace toposortDAG
{
    using namespace std;

    class Vertex
    {
    public:
        Vertex(string s)
        {
            name = s;
            tempMarked = false;
            permMarked = false;
        }

        void addRoute(string t)
        {
            if(find(toNames.begin(),toNames.end(),t) == toNames.end())
            {
                toNames.push_back(t);
            }
        }
        string name;
        vector<string> toNames;

        bool tempMarked;
        bool permMarked;
    };

    typedef shared_ptr<Vertex> VP;

    class Graph 
    {
    public:
        void addVertex(string s);
        void addRoute(string from, string to);
        vector<VP> m_vertexes;
        map<string,VP> m_mapOfVertexes;

        vector<string> topoSort();
        bool visit(VP p, vector<string> &ListNames);
    };

    void Graph::addVertex(string s)
    {
        if(m_mapOfVertexes[s] == nullptr)
        {
            VP p = make_shared<Vertex>(Vertex(s));
            m_vertexes.push_back(p);
            m_mapOfVertexes[s] = p;
        }
    }

    void Graph::addRoute(string from, string to)
    {
        addVertex(from);
        addVertex(to);
        VP p = m_mapOfVertexes[from];
        p->addRoute(to);
    }

    /*
    L ¡û Empty list that will contain the sorted nodes
        while there are unmarked nodes do
            select an unmarked node n
            visit(n)

            function visit(node n)
            if n has a permanent mark then return
                if n has a temporary mark then stop(not a DAG)
                    mark n temporarily
                    for each node m with an edge from n to m do
                        visit(m)
                        mark n permanently
                        add n to head of L
                        */
    
    vector<string> Graph::topoSort()
    {
        vector<string> L;
        for(auto p : m_vertexes)
        {
            if(!p->permMarked && !p->tempMarked)
            {
                if(!visit(p, L))
                {
                    break;
                }
            }
        }
        return L;
    }

    bool Graph::visit(VP p, vector<string> &L)
    {
        if(p->permMarked)
        {
            return true;
        }

        if(p->tempMarked)
        {
            return false;
        }

        p->tempMarked = true;
        for(string name : p->toNames)
        {
            VP m = m_mapOfVertexes[name];
            if(!visit(m, L))
            {
                return false;
            }
        }
        p->permMarked = true;
        L.push_back(p->name);
    }
}

void topoSortMain()
{
    using namespace std;
    using namespace toposortDAG;

    Graph g;
    g.addRoute("d", "f");
    g.addRoute("e", "g");
    g.addRoute("f", "g");
    g.addRoute("g", "h");
    g.addRoute("a","d");
    g.addRoute("b", "d");
    g.addRoute("c", "d");
    g.addRoute("d", "e");
    
    vector<string>  p = g.topoSort();
    for(string a: p)
    {
        cout<< a << endl;
    }


}