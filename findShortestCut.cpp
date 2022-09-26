

// Dijkstra method to find the closest path in a graph:

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <string>

using namespace std;

class  Route
{
public:
    string nameTo;
    int weight;

    Route(string name, int w)
    {
        nameTo = name;
        weight = w;
    }
    ~Route()
    {
        int mm = 0;
    }

    Route(Route &&r)
    {
        nameTo = std::move(r.nameTo);
        weight = std::move(r.weight);
    }
    bool operator == (const Route &o)
    {
        return nameTo == o.nameTo;
    }

    void operator = (const Route &o)
    {
        if(this != &o)
        {
            nameTo = o.nameTo;
            weight = o.weight;
        }
    }
};

typedef std::vector<string> Path;

class Vertex
{
public:
    Vertex(){};
    Vertex(string name)
    {
        m_name = name;
        m_smallestWeight = INT_MAX;
        m_smallestPath.push_back(name);
    }

    ~Vertex()
    {
        int mm = 0;
    }

    void addRoute(string nameTo, int weight)
    {
        if(m_mapRoutes[nameTo] == 0)
        {
            std::shared_ptr<Route> r = make_shared<Route>(Route(nameTo, weight));
            m_RoutesTo.push_back(r);
            m_mapRoutes[nameTo] = r;
        }
    }

    int m_smallestWeight;
    Path m_smallestPath;

    string m_name;
    vector<shared_ptr<Route>> m_RoutesTo;
    std::map<string, shared_ptr<Route>> m_mapRoutes;
};

typedef std::vector<string> PATH;

class Graph
{
public:
    void addRoute(const string &a, const string &b, int weight);
    void addSingleRoute(const string &a, const string &b, int weight);
    PATH getShortestCut(string nameFrom, string nameTo);

protected:

    void findShortestCut(const string &from, const string &to);
    void addVertex(string name);

    vector<shared_ptr<Vertex>> m_vertexes;
    map< string, shared_ptr<Vertex>> m_mapVertexes;
};

void Graph::addVertex(string name)
{
    if(m_mapVertexes[name]!=nullptr)
    {
        return;
    }

    shared_ptr<Vertex> newVertex = make_shared<Vertex>(name);
    m_vertexes.push_back(newVertex);
    m_mapVertexes[name]=newVertex;
}

void Graph::addRoute(const string &a, const string &b, int weight)
{
    addSingleRoute(a,b,weight);
    addSingleRoute(b,a,weight);
}

void Graph::addSingleRoute(const string &a, const string &b , int weight)
{
    addVertex(a);
    addVertex(b);

    shared_ptr<Vertex> p = m_mapVertexes[a];
    p->addRoute(b, weight);
}

void Graph::findShortestCut(const string &fromName, const string &toName)
{
    if(fromName == toName)
    {
        return;
    }

    shared_ptr<Vertex> fromVertex = m_mapVertexes[fromName];
    if(!fromVertex)
    {
        return;
    }

    PATH path = fromVertex->m_smallestPath;
    int weight = fromVertex->m_smallestWeight;

    if ( find(path.begin(), path.end(), toName) != path.end() )
    {
        return;
    }

    if(fromVertex->m_RoutesTo.size() > 0)
    {
        for(shared_ptr<Route> route : fromVertex->m_RoutesTo)
        {
            shared_ptr<Vertex> toVetex = m_mapVertexes[route->nameTo];
            
            int newWeight = weight + route->weight;
            if( toVetex->m_smallestWeight > newWeight)
            {
                toVetex->m_smallestWeight = newWeight;
                toVetex->m_smallestPath = path;
                toVetex->m_smallestPath.push_back(route->nameTo);

                findShortestCut(route->nameTo,toName);
            }
        }
    }

    return;

}

PATH Graph::getShortestCut(string nameFrom, string nameTo)
{
    findShortestCut(nameFrom,nameTo);
    auto v = m_mapVertexes[nameTo];
    return v->m_smallestPath;
}

void findShortestCutMain()
{
    Graph g;
    g.addRoute("a","b",1);
    g.addRoute("a","c",5);
    g.addRoute("b","d",1);
    g.addRoute("c","d",1);
    g.addRoute("d","e",2);
    g.addRoute("e", "f", 3);
    g.addRoute("b", "f", 10);

    PATH p = g.getShortestCut("f","a");

    for(auto name : p)
    {
        cout << name << endl;
    }
    //g.m_mapVertexes["b"].m_smallestPath;


}