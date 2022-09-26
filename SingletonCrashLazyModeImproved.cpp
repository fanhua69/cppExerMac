class BSingleton;

class ASingleton{
public:
    static ASingleton& getInstance();
    /* more (non-static) functions here */

private:
    ASingleton()
    {
        int m = 0;
    };// ctor hidden
    ~ASingleton(){}; // dtor hidden
};

class BSingleton
{
public:
    static BSingleton& getInstance();
    /* more (non-static) functions here */

private:
    BSingleton()
    {
        int m = 0;
    };// ctor hidden
    ~BSingleton(){}; // dtor hidden
};


ASingleton& ASingleton::getInstance()
{
    const BSingleton& b = BSingleton::getInstance();
    static ASingleton theSingleton;
    return theSingleton;
}

BSingleton& BSingleton::getInstance()
{
    const ASingleton & b = ASingleton::getInstance();
    static BSingleton theSingleton;
    return theSingleton;
}

void singletonLazyMode()
{
    ASingleton &a = ASingleton::getInstance();
}