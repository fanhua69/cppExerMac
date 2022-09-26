
#include <iostream>

using namespace std;

template <typename T>
struct IsConst
{
    enum
    {
        isConst = 0
    };
};

template <typename T>
struct IsConst<const T>
{
    enum
    {
        isConst = 1
    };
};

template <typename T>
void print(T &val)
{
    cout << IsConst<T>::isConst << endl; //prints 0
}

int templatespecialization4()
{
    const int x = 10;
    print(x); //why dynamic argument deduction deducting it as normal integer?
    cout << IsConst<const int>::isConst << endl; //prints 1
    return 0;
}