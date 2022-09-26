

#include <string>
#include <thread>
#include <iostream>
#include <functional>
using namespace std;

void ChangeCurrentMissileTarget(string& targetCity)
{
    targetCity = "Metropolis";
    cout << " Changing The Target City To " << targetCity << endl;
}


class testFunctor
{
public:
    void operator ()()
    {
        m=2222;
    }
    int m=1111;
};
int threadpassingref()
{
    string targetCity = "Star City";
    cout << "Current Target City is " << targetCity << endl;
    thread t1(ChangeCurrentMissileTarget, std::ref(targetCity));
    t1.join();
    cout << "Current Target City is " << targetCity << endl;

    testFunctor f;
    cout << "Before thread Value:" << f.m << endl;
    thread t2(std::ref(f));
    cout << "Current Value:" << f.m << endl;
    t2.join();

    return 0;
}
