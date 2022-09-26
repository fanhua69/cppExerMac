


class MyClassC
{
public:
        MyClassC()
        {
            m_a = 10;
            m_b = 20;
        }

        MyClassC (int a)
        {
            m_a = a;
            m_b = 144;
        }

        MyClassC(int a, int b)
        {
            m_a = a;
            m_b = b;
        }

private:
    int m_a;
    int m_b;

public:
    static int m_c;

    static int getC()
    {
        return m_c;
    }
};

int MyClassC::m_c = 10;

void MyClassMain()
{
    MyClassC c[3]{ {3,4},{1,2},{5,6}};
    c[0].m_c = 20;
    MyClassC::m_c = 30;
    int cv = c[0].getC();

}