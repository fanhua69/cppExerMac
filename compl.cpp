

#include <iostream>
#include <bitset>
#include <iso646.h>

int complmain()
{
    std::bitset<4> x("G100");
    std::bitset<4> y("0111");
    y and_eq x;
    std::cout << y << '\n';

    return 0;
}