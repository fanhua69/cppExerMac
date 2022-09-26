

#include <iostream>

using namespace std;

void lvalueref()
{
  float a = 1.0f;
  cout << (int)a << endl;
  cout << (int&)a << endl;    // = "int &x = a;"
  cout << boolalpha << ((int)a == (int&)a) << endl; // 输出什么？


  float b = 0.0f;
  cout << (int)b << endl;
  cout << (int&)b << endl;
  cout << boolalpha << ((int)b == (int&)b) << endl; // 输出什么？
}