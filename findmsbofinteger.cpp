

// Simple CPP program to find MSB number
// for given n.
#include <iostream>
using namespace std;

int setBitNumber(int n)
{
    if ( n == 0 )
        return 0;

    int msb = 0;
    while ( n != 0 )
    {
        n = n / 2;
        msb++;
    }

    return (1 << msb);
}

// Driver code
int findmsbofinteger()
{
    int n = 0;
    cout << setBitNumber(n);
    return 0;
}