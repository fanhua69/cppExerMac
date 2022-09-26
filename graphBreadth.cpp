

#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <queue>
#include <string>

using namespace std;

namespace breadthGraph
{
    class Vertex
    {
    public:
        Vertex(string a)
        {
            name = a;
        }

        void addRoute(string b)
        {
            toVertexes.push_back(b);
        }

        string name;
        vector<string> toVertexes;
    };

    typedef shared_ptr<Vertex> VP;

    class Graph
    {
    public:
        void addRoute(string a, string b);
        void addVertex(string a);
        vector<string> breadthTraversal(string head);

    protected:

        std::vector<VP> vertexes;
        map<string, VP> mapVertexes;
    };

    void Graph::addVertex(string a)
    {
        if(mapVertexes[a] == nullptr)
        {
            VP p = make_shared<Vertex>(a);
            mapVertexes[a] = p;
        }
    }

    void Graph::addRoute(string a, string b)
    {
        addVertex(a);
        addVertex(b);
        shared_ptr<Vertex> p  = mapVertexes[a];
        p->addRoute(b);
    }

    vector<string> Graph::breadthTraversal(string head)
    {
        vector<string> vertexesReturn;
        map<string, int> mapFoundVertexes;
        queue<string> vertexes;
        vertexes.push(head);

        while(!vertexes.empty())
        {
            string name = vertexes.front();
            vertexesReturn.push_back(name);
            vertexes.pop();

            VP v = mapVertexes[name];
            for(string c : v->toVertexes)
            {
                if(mapFoundVertexes[c] == 0)
                {
                    vertexes.push(c);
                    mapFoundVertexes[c]++;
                }
            }
        }

        return vertexesReturn;
    }
}

using namespace breadthGraph;

void breadthTraversalMain()
{
    Graph g;
    g.addRoute("a","b");
    g.addRoute("a","c");
    g.addRoute("b","d");
    g.addRoute("b","e");
    g.addRoute("c", "d");
    g.addRoute("d","f");
    g.addRoute("e","f");

    vector<string> p = g.breadthTraversal("a");
    for(string s : p)
    {
        cout << s << endl;
    }

}