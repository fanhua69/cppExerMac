

extern "C" void callll();


const int * constf(float a)  
{
    static int i = a*2;
    i = a*2;
    return &i;
}

int testd(const int *(*f)(float), float d)
{
    int a = *(f(d));
    return a;
}

void constcastmain()
{
    volatile int a = 1234;

    int * pp = const_cast<int*>(&a);
    volatile int * ppp = const_cast<volatile int*>(pp);

    int i = 1234;
    const int *p = &i;
    int *pi = const_cast<int*> (p);

    *pi = 3455;
    const int *p2 = const_cast<const int*>(pi);
    *pi = 34;

    const int* (*f)(float) = constf;
    auto ff = constf;
    const int *d = f(10);
    const int *d2 = (*f)(20);
    auto aa1 = ff(23);
    auto aa2 = (*ff)(234);
    int aaa = testd(ff,56);


}