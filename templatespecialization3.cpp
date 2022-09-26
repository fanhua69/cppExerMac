

#include <iostream>

#include <string>

using namespace std;

template<class T, class T2>
int compareBig(T a,T2 b)
{
    return a < b;
}

template<bool, int>
int compareBig(bool a, int b)
{
    return a < b;
}

template<class T>
int compareBig(bool a, T b)
{
    return a < b;
}

template <int>
int compareBig(int a)
{
    return a > 1;
}

void templatespecialization3()
{
    int a = 1 ;
    int b = 2;
    double c = 3.4;
    bool bb = true;
    bool cc = false;

    cout << compareBig(a, c) << endl;
    cout << compareBig<5>(a) << endl;
    cout << compareBig(bb, c) << endl;

}