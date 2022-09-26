
extern "C" void testcppcaller();

class aaav
{
public:
    int m;
};
class testcppaaa
{
public :

    void testcppf()
    {}

    const static int m_n ; // error
};

const int testcppaaa::m_n = {1};

testcppaaa a1a;

void testcppcaller()
{
    //a1a.m_n = 10;
    a1a.testcppf();
}
