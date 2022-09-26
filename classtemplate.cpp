
#include <iostream>

using namespace std;


template<class T1>
class CMyPair
{
public:
    CMyPair (T1);
};

template<>
class CMyPair<char>
{
public:
    CMyPair(char);
};

template<class T1>
CMyPair<T1>::CMyPair(T1 a)
{
}

//template<>
CMyPair<char>::CMyPair(char)
{}



template <class T1,class T2>
T1 checkData(T1, T2)
{
    return T1();
}


//template<>
char checkData(char, int)
{
    return 'c';
}

void classtemplatemain()
{
    checkData('c',10);
    char c = 'c';//checkData('c','c');
    char d = 97;
    char e = 'b';

    cout << "DDD:" <<(int) c <<endl;
    cout << "EEE:" << d << endl;
    cout << "EEE:" << (int)e << endl;

}