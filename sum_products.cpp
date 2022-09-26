

#include <numeric>
#include <iostream>
#include <functional>

#include <list>

using namespace std;

int op1(int a, int b)
{
    return a+b;
}

int op2(int a, int b, int (*f)(int, int))
{
    return (*f)(a,b);
}

void sumproductmain()
{
    using namespace std::placeholders;
    list<int> q = { 1,2,3,4,5};
    list<int> w = { 2,2,2,2,2};

    auto op3 = bind(op2,_1,_2,op1);
    int n = std::inner_product(q.begin(),q.end(),w.begin(),1,op1,op3);
    cout << n << endl;
}