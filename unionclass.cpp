

union myunion
{
    int a;
    char b;
    double c;
    myunion()
    {
        c = 1.0;
        a = 2;
        b = 3;
    }

    myunion(int a)
    {
        this->a = a;
    }

    int getA()
    {
        return a;
    }
};

void myunionmain()
{
    myunion u;
    myunion v(4);
    int a = v.getA();
}