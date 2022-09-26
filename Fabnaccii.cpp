

#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

std::unordered_map<int, int> Fabs;

int Fab(int n)
{
    if(n==1 ||n ==2)
    {
        return 1;
    }

    if(Fabs.find(n)!=Fabs.end())
    {
        cout << "Found " << n << endl;
        return Fabs.at(n);
    }

    int d = Fab(n-1)+Fab(n-2);
    Fabs[n]=d;

    return d;
}

int F(int n)
{
    if(n<2)
    {
        return 1;
    }

    int n1=1;
    int n2=1;
    int n3=0;

    int i=3;
    while(i++<=n)
    {
        n3=n1+n2;
        n1=n2;
        n2=n3;
    }

    return n3;
}

void FabsMain()
{
    cout << Fab(30) << endl;
    cout << F(30) << endl;
}