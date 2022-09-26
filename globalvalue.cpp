
#include <stdio.h>
#include <iostream>

using namespace std;

int x = 1234;

int modifyvalue()
{
  return(x += 10);  // here is modifying global x, returned the global value of x
}

int changevalue(int x) // this is not a reference, so that no change x
{
  return(x += 1); // returned x
}

struct Test
{
  Test(int)
  {
  }
  Test()
  {
    int m = 0;
  }
  void fun()
  {
  }

  int n = 0;
};

void globalvalue()
{
  Test b();

  int x = 10;
  x++;
  int n = changevalue(x);
  x++;
  int n2 = modifyvalue();
  printf("First output:%d\n", x);

  x++;
  changevalue(x);
  printf("Second output:%d\n", x);
  modifyvalue();
  printf("Third output:%d\n", x);

  char str1[] = "abc";
  char str2[] = "abc";
  const char str3[] = "abc";
  const char str4[] = "abc";
  char* str5 = "abc";
  char* str6 = "abc";
  cout << boolalpha << (str1 == str2) << endl; // 输出什么？
  cout << boolalpha << (str3 == str4) << endl; // 输出什么？
  cout << boolalpha << (str5 == str6) << endl; // 输出什么？


}