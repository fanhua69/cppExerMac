
#include <vector>
#include <iostream>
using namespace std;

int findFirstMissingInteger(vector<int> &a)
{
    int i = 0;
    for ( int j = 0; j < a.size(); j++ )
    {
        if ( a[j] <= 0 )
        {
            swap(a[i], a[j]);
            i++;
        }
    }

    int pb = 0;
    for ( int i = 0; i < a.size(); i++ )
    {
        if ( a[i] > 0 )
        {
            pb = i;
            break;
        }
    }

    //
    for ( int i = pb; i < a.size(); i++ )
    {
        int k = abs(a[i]) - 1;
        if ( k >= 0 && k < a.size() )
        {
            a[k] = -abs(a[k]);
        }
    }

    for ( int i = 0; i < a.size(); i++ )
    {
        if ( a[i] > 0 )
        {
            return i + 1;
        }
    }

    return a.size() + 1;
}

void findFirstMissingIntegerMain()
{
    vector<int> a={1,2,3,4,5};

    cout << findFirstMissingInteger(a) << endl;
}