
// binary_function example
#include <iostream>     // std::cout, std::cin
#include <functional>   // std::binary_function

using namespace std;
struct MyCompare : public std::binary_function<int, int, bool>
{
    bool operator() (int a, int b) const
    {
        return (a < b);
    }
};

int binaryfunctionmain2()
{
    MyCompare Compare_object;
    //Compare::first_argument_type input1;
    //Compare::second_argument_type input2;
    //Compare::result_type result;

    auto a = std::bind1st(Compare_object,11);
    cout << a(5) << endl;
    cout << a(12) << endl;

    auto b = std::bind2nd(Compare_object,11);
    cout << b(5) << endl;
    cout << b(12) << endl;


    return 0;
}