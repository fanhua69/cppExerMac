
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <int val>
class AddIt
{
public:
    int m_val = val;

    int operator ()(int &e)
    {
        e += m_val;
        return e;
    }
};


void printItAA(int n)
{
    cout << n << endl;
}

void nontypeTemplateParameter()
{
    vector<int> a = {1,2,3,4,5};

    AddIt<7> addIt;

    for(int &e : a)
    {
        addIt(e);
    }
    
    AddIt<8> i;
    std::for_each(a.begin(),a.end(),i);

    for_each(std::begin(a),end(a),printItAA);
}