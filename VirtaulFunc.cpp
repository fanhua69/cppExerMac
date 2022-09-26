

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Building
{

public:
    int left;
    int right;
    int height;

    Building()
    {
        cout << "constructor in building"<< endl; 
        test();
    }

    ~Building()
    {
        cout << "destructor in building" <<endl;
        test();
    }

    bool operator < (const Building &o) const
    { 
        return left<o.left;
    };

    virtual void test()
    {
        cout << "test in building"<< endl;
    }
};

class Building2 : public Building
{
public:
    Building2()
    {
        cout << "constructor in building 2" << endl;
        test();
    }
    ~Building2()
    {
        cout << "destructor in building 2" << endl;
        test();
    }

    virtual bool operator < (const Building &o) const
    {
        return right < o.right;
    }
    virtual void test()
    {
        cout << "test in building 2" << endl;
    }
};

class Building3:public Building2
{
public:
    Building3()
    {
        cout << "constructor in building 3" << endl;
        test();
    }
    ~Building3()
    {
        cout << "destructor in building 3" << endl;
        test();
    }
    virtual void test()
    {
        cout << "test in building 3" << endl;
    }
};

class Building4 :public Building3
{
public:
    Building4()
    {
        cout << "constructor in building 4" << endl;
        test();
    }
    ~Building4()
    {
        cout << "destructor in building 4" << endl;
        test();
    }
    virtual void test()
    {
        cout << "test in building 4" << endl;
    }
};

void virtualFunction()
{
   // Building b;
   // BuildingLeft a;
  //  BuildingRight c;
   // Building4 c;
}