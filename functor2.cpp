

#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <vector>
#include <iomanip>
#include <functional>
#include <array>


class box
{
public:
    box(){m_data = 23;}
    friend double operator +( double , box);
public:
    int m_data;
};

double operator + (double a, box b)
{
    return a + b.m_data;
}


using namespace std;

template <int T2>
double power( char a)
{
    return (int)a * T2;
}

template <typename T1, char T2>
double power(int a)
{
    return (int)a * (int)a;
}
//template<typename T, int duration>
//double power(double a, int f = 1000)
//{
//    return a + f + duration ;
//}

class CountFrom
{
private:
    int &count;
public:
    CountFrom(int &n) : count(n)
    {
    }
    int operator()()
    {
        return count++;
    }
};

double fun(int a, int b,int c)
{
    return a+b;
}


int functor2main()
{
    using C = char;
    C c;
    c = 'c';

    double  a1 = (100 + 1.0/3) -100;
    double b1 = 1.0/3;
    bool c1 = a1 == b1;


    typedef int* myint[150];

    myint f111;

    f111[10] = new int [10];

    unsigned int nsize= 0x7fffffff / 5;
    
    int *pppsdf = nullptr;
    try
    {
        int *pppsdf= new int[nsize];
    }
    catch(exception e)
    {
        cout << e.what() <<endl;
    }
    for(int i=0;i<nsize;i++)
    {
        pppsdf[i]=i;
    }

    array<array<int,5>,10> a;
    a[4][3] = 1;

    array<int, 10> b;
    for(int i=0;i<10;i++)
    {
        b[i] = i;
    }
    array<int,10>::reverse_iterator ita= b.rbegin();
    while(ita!=b.rend())
    {
        cout << *ita++ << endl;
        
    }
    using namespace std::placeholders;

    auto fff = std::bind(fun, 10, _2,_1);
    fff(2,3);
    
    const type_info &infoV = typeid(fff);

    cout << typeid(fff).name() << endl;

    double x = 123.43 + box();
    auto f = power<10>;

    double d = f('a');
   // d = power<char,int>(1.1,23);
   // double d1 = power<int, double>(10);


    std::istringstream streamA("0.1 0.2 0.3 0.4");
    std::istream_iterator<double> it = istream_iterator<double>(streamA);
    while(it != istream_iterator<double>())
    {
        cout << *it << endl;
        it++;
    }

    std::ostream_iterator<double> it2 = ostream_iterator<double>(std::cout,"\n");
    for(int i = 0; i< 4; i++)
    {
        *it2 = i;
    }

    std::partial_sum(std::istream_iterator<double>(streamA),
                     std::istream_iterator<double>(),
                     std::ostream_iterator<double>(std::cout, " "));


    int state = 1120;
    vector<int> dataa;
    dataa.reserve(100);
    dataa.resize(11);
    //std::generate_n(std::ostream_iterator<int>(std::cout, "\n"), 11, CountFrom(state));
    std::generate_n(dataa.begin(), 11, CountFrom(state));

    double pi = 3.14156;
    cout << setw (3) << pi<< " " << pi << " " <<pi << endl;
    for(int i: dataa)
    {
        cout << i <<  endl;
    }

    vector<int>::iterator it3 =  find_if(dataa.begin(),dataa.end(),[](int a){return a == 1123;});
    cout << "Found :" << *it3<<endl;

    return 0;
}