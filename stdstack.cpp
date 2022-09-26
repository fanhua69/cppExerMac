

#include <stack>



void stdstackmain()
{
    std::stack<int> a;
    std::stack<int> b;
    a.push(1);
    b.push(2);
    a.swap(b);
    std::pair <int, char> c;
    std::pair <int, char> d;
    c.first = 1;
    c.second = 2;
    d.first = 3;
    d.second = 4;

    c.swap(d);
}