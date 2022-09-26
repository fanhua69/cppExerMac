
// C++ program to demonstrate std::inserter
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
int stdinsertermain()
{
    // Declaring first container
    vector<int> v1 = { 1, 2, 3, 7, 8, 9 };

    // Declaring second container
    vector<int> v2 = { 4, 5, 6 };

    vector<int>::iterator i1;
    i1 = v2.begin() + 2;
    // i1 points to next element of 5 in v2

    // Using std::inserter inside std::copy
    std::copy(v1.begin(), v1.end(), std::inserter(v2, i1));
    // v2 now contains 4 5 1 2 3 7 8 9 6

    // Displaying v1 and v2
    cout << "v1 = ";

    int i;
    for ( i = 0; i < 6; ++i )
    {
        cout << v1[i] << " ";
    }

    cout << "\nv2 = ";
    for ( i = 0; i < 9; ++i )
    {
        cout << v2[i] << " ";
    }

    return 0;
}
