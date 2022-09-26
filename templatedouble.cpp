

#include <iostream>

extern const double kMyDouble = 0.1;;

template <const double* MyDouble>
void writeDouble()
{
    std::cout << *MyDouble << std::endl;
}

int templatedouble()
{
    writeDouble<&kMyDouble>();
    return 0;
}