

class descall
{
public:
    descall()
    {
        m_p = new int [100];
    }
    ~descall()
    {
        delete []m_p;
    }
    int * m_p;
};

void descallmain()
{
    descall();
    descall a;
//    a.~descall();    
}