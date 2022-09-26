

namespace mya
{
    int m;
    namespace myb
    {
        int m;
    }
}

void namespacemain()
{
    mya::m = 0;
    mya::myb::m = 11;

    int n = mya::m;
    int b = mya::myb::m;

    //mya::n = 10;


}