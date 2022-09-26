
class aaa
{
public:
    aaa(){ m = 1;}
    int m;
};

class bbb
{
public:
    bbb(){n = 4;};
    bbb(int nn){n = nn;}
    int n;
};

template <class T>
struct ccc
{
    ccc()
    {
        a = b;
    }
    T a;
    T b;
};

template <>
struct ccc<bbb>
{
    ccc()
    {
       m_a = 10;
       m_b = 20;
    }
    bbb m_a;
    bbb m_b;
};

template <>
struct ccc<int>
{
};

template <int f>
struct ddd
{
};

template <int v>
struct AAA
{
    AAA()
    {
        m_data = v;
    }
    int m_data;

    enum 
    {
        BLUE  = v,
        GREEN = v+ 2,
        Black = v+ 3
    };

};


void templateint()
{
    AAA<5> a;

    int n = AAA<6>::BLUE;


    ccc <aaa> aa;
    ccc <bbb> b;
    ccc <int> c;
    ddd <8> d;

}