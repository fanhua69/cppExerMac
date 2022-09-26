

#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class testmove
{
public:
    testmove()
    {
        m = 0;
        p = nullptr;
    };

    testmove(const testmove& o):p(new int[o.m])
    {
        m = o.m;
    }

    testmove(testmove &&o)
    {
        m=o.m;
        p = std::move (o.p);
    }

    testmove & operator = (const testmove &o) 
    {
        m = o.m;
        p = std::make_unique<int []> (o.m);
        memcpy((void*)p.get(),(void*)o.p.get(),sizeof(int)*m);
        return *this;
    }

    testmove & operator = (testmove &&o)
    {
        m = o.m;
        p = std::move(o.p);

        o.m = 0;


        return *this;
    }

    int m ;
    std::unique_ptr<int[]> p;

};

testmove gettestmove()
{
    testmove a;
    a.m = 10;
    a.p = make_unique<int []>(a.m);
    a.p[0] = 1;
    a.p[1] = 2;
    a.p[3] = 3;
    a.p[4] = 4;
    a.p[5] = 5;
    a.p[6] = 6;
    a.p[9] = 10;


    return a;
}



void stdmove()
{

    std::vector< int > vec { 1,2,3,4,5 };
    std::vector< int > mvec { 6,7,8,9,0 };

    mvec = std::move(vec);


    testmove a;
    testmove b = gettestmove();
    a = testmove();

    std::cout << vec.size() << std::endl;
    std::cout << mvec.size() << std::endl;

}