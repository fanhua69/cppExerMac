


#include <iostream>

using namespace std;

class AAAAA
{};

void typeidmain()
{
    AAAAA *p = new AAAAA;
    const std::type_info &i = typeid(p);
    cout << i.name() << endl;
    cout << i.raw_name() << endl;
    cout << i.hash_code() << endl;


    int myint = 123;
    const std::type_info& r2 = typeid(std::printf("%d\n", myint));
    cout << '\n' << "std::cout<<myint has type : " << r2.name() << '\n';

}