

struct X
{
    bool operator<(X)
    {
        return true;
    }

    bool operator > (int)
    {
        return false;
    }
} x;


int operator|(bool (X::*)(int), X a)
{
    return 0;
}

void OperatorOr()
{

 
    int r = &(X::operator>) | x;
}
