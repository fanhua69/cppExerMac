

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Given the following flight routes, print all possible routes between the airports C and D


//  A <----> B
//  A <----> C
//  A <----> D
//  B <----> C
//  B <----> D


// C,A,B,D,
// C,A,D,
// C,B,A,D,
// C,B,D,

// one method: add a direct route between two airport
// 2nd: print all routes between two airports

class Node
{
public:
    Node()
    {}
    Node(string a)
    {
        m_nameFrom = a;
    }
    std::string m_nameFrom;
    std::vector<string> m_namesTo;
};

typedef std::vector<string> path;

class IAirportComm
{
public:
    virtual void addRoute(const string &a, const string &b) = 0;
    virtual path findAllRoutes(const string &a, const string &b) = 0;
};

class AirPortComm
{
public:
    void addRoute(const string &a, const string &b);
    void addUnidirectionRoute(const string &a, const string &b);
    virtual bool findAllRoutes(const Node &a, const string &b, path p, std::vector<path> &returnPath);
    std::vector<path> findAllRoutes(const string &a, const string &b);
    void printPath(const std::vector<path> &p);

    ~AirPortComm()
    {
        for(auto p : m_nodes)
        {
            delete p;
        }
    }

protected:
    std::vector<Node*> m_nodes;
    std::map<string, Node*> m_mapNodes;
};

void AirPortComm::addRoute(const string &a, const string &b)
{
    addUnidirectionRoute(a,b);
    addUnidirectionRoute(b,a);
}

void AirPortComm::addUnidirectionRoute(const string &a, const string &b)
{
    bool foundNodeA = false;
    bool foundNodeB = false;
    for ( auto n : m_nodes )
    {
        if(n->m_nameFrom == a)
        {
            if(std::find(n->m_namesTo.begin(),n->m_namesTo.end(),b)==n->m_namesTo.end())
            {
                n->m_namesTo.push_back(b);
            }
            foundNodeA = true;
        }

        if(n->m_nameFrom == b)
        {
            foundNodeB = true;
        }

        if(foundNodeA && foundNodeB)
        {
            break;
        }
    }
 
    if ( !foundNodeA )
    {
        Node *newNode = new Node(a);
        newNode->m_namesTo.push_back(b);
        m_nodes.push_back(newNode);
        m_mapNodes[a] = newNode;
    }

    if(!foundNodeB)
    {
        Node *newNode = new Node(b);
        m_nodes.push_back(newNode);
        m_mapNodes[b] = newNode;
    }
}

bool AirPortComm::findAllRoutes(const Node &a, const string &b, path p, std::vector<path> &returnPaths)
{
    // To prevent from a dead loop when we have looped the node:
    if ( std::find(p.begin(), p.end(), a.m_nameFrom) != p.end() )
    {
        return false;
    }

    //
    p.push_back(a.m_nameFrom);

    if ( a.m_nameFrom == b)
    {
        returnPaths.push_back(p);
        return true;
    }

    for ( auto n : a.m_namesTo)
    {
        Node *nextNode  = m_mapNodes[n];
        if(nextNode)
        {
            findAllRoutes(*nextNode, b, p, returnPaths);
        }
    }

    return false;
}

std::vector<path> AirPortComm::findAllRoutes(const string &a, const string &b)
{
    path p;
    std::vector<path> returnPaths;
    Node *n = m_mapNodes[a];
    findAllRoutes(*n,b,p, returnPaths);

    return returnPaths;
}

void AirPortComm::printPath(const std::vector<path> &ps)
{
    for(auto p: ps)
    {
        cout << "Route:" ;

        int i = 0;
        for ( auto n : p )
        {
            cout << n ;
            if( i != p.size() - 1)
            {
                cout << "," ;
            }
            i++;
        }
        cout << endl;
    }
}

int findAllRoutesMain()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    AirPortComm apc;
    //  A <----> B
    //  A <----> C
    //  A <----> D
    //  B <----> C
    //  B <----> D
    // C,A,B,D,
    // C,A,D,
    // C,B,A,D,
    // C,B,D,
    apc.addRoute("a", "b");
    apc.addRoute("a", "c");
    apc.addRoute("a", "d");
    apc.addRoute("b", "c");
    apc.addRoute("b", "d");


    std::vector<path> p = apc.findAllRoutes("a", "d");
    
    apc.printPath(p);
    return 0;
}
