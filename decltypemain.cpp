

#include <iostream>
using namespace std;

#include <vector>
double *ffff1()
{
  return nullptr;
}


void decltypemain()
{
  double * (*ffff)();
  ffff= ffff1;

  double * p = (*ffff)();
  cout << "type of ffff:" << typeid(ffff).name() << endl;

  long double ld = 3.1415926536; 
  long double aa = { 12 }, bb = { ld };


  const std::vector<int> v(10);
  cout << "type of v:" << typeid(v).name() << endl;

  double w(1.123454);


  decltype (w) ff;
  auto a = v[0];        // a 的类型是 int
  decltype(v[0]) b = 1; // b 的类型是 const int&, 因为函数的返回类型是
                        // std::vector<int>::operator[](size_type) const
  auto c = 0;           // c 的类型是 int
  auto d = c;           // d 的类型是 int
  decltype(c) e = c ;        // e 的类型是 int, 因为 c 的类型是int
  e = 1234;

  decltype((c)) f = c;  // f 的类型是 int&, 因为 (c) 是左值

  f =123;

  cout << "type of f:" << typeid(f).name()<< endl;

  int &fh1 = c;
  cout << "type of fh1:" << typeid(fh1).name() << endl;

  int *fh2 = &c;
  cout << "type of fh2:" << typeid(fh2).name() << endl;


  decltype(0) g;        // g 的类型是 int, 因为 0 是右值
}