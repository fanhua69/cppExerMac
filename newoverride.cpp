

namespace newoverride
{
    class A
    {
    private:
      //  void * operator new(size_t ){};
    public:
        A(){};
    };
}

void newoveridemain()
{
    using namespace newoverride;
    A * a = new A;
    A b;

}