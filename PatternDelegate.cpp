
template <class T>
class CCallback
{
public:
    typedef void (T::*fn)(int arg);

    CCallback(T& trg, fn op)
        : m_rTarget(trg)
        , m_Operation(op)
    {
    }

    void Execute(int in)
    {
        (m_rTarget.*m_Operation)(in);
    }

private:

    CCallback();
    CCallback(const CCallback&);

    T& m_rTarget;
    fn m_Operation;

};

class A
{
public:
    virtual void Fn(int i)
    {
    }
};


int patterndelegate(int /*argc*/, char * /*argv*/)
{
    A a;
    CCallback<A> cbk(a, &A::Fn);
    cbk.Execute(3);
    return 0;
}