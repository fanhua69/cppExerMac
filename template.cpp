

#include <iostream>

using namespace std;

template <typename First, typename Second, int Third>
class SomeType;

template <typename Second>
using TypedefName = SomeType<double, Second, 5>;

typedef void(*PFD)(double);    // C ��ʽ
using PF = void(*)(double);    // using����C��ʽ������

void a()
{
   auto pp = [](int)->void{};  // using�ͺ����������ͺ����﷨
}

// Iterate Expand Parameter Package:
void print()
{
  cout << "Empty" << endl;
}

template < typename T, typename ...TT>
void print(T first, TT ...  rest)
{
  cout << first << "\n";
  print(rest...);
}

// Use ... to expand the parameter package:
template <class T>
void printarg(T t)
{
  cout << t << endl;
}

template <class ...Args>
void expandargs(Args... args)
{
  int arr[] = {
    (printarg(args), 1)...};
}



// Calling function:
void templateex()
{
  int x, y, z;
  x = y = 1;
  z = (x++, y++, y++);
  printf("%d,%d,%d\n", x, y, z);

  int a,b,c;
  int n = (a = 3,b = 5,b += a,c = b * 5);
  int t;
  double d=(t = 1, t + 5, t++);
  //expandargs(1,2,3,4);
}

