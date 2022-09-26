
#include <iostream>

#include <typeinfo>
using namespace std;

void datagroup()
{
  int a[3][2] = {1,2,3,4,5,6};
  //std::cout << *a[1] << std::endl;
  //std::cout << a << std::endl;
  std::cout << a+1 << std::endl;
  std::cout << a + 2 << std::endl;


  int b[5] = {1,2,3,4,5};
  std::cout << b << std::endl;
  std::cout << b + 1 << std::endl;

  std::cout << &b + 1 << std::endl;

  auto c = &b;
  std::cout << typeid(c).name() <<std::endl;

  // c = &a; error;

  //std::cout << *a << std::endl;
  //std::cout << *(a + 1) << std::endl;
  //std::cout << *(a + 2) << std::endl;

  //char a[5] = {'A','b','C','D'};
  //char (*p3)[5] = &a;
  //char * p1[10];
  //*(p1[0]) = 'a';
  //*(p1[1])= 'b';
  //*(p1[2])= 'c';
  //*(p1[3])= 'd';

  //int c[3][3] = {1,2,3,4,5,6,7,8,9};
  //for(int i=0;i<3;i++)
  //  for(int j=0;j<3;j++)
  //  {
  //    printf("%ld,",c[j]);
  //    printf("%ld\n", &c[j]);
  //  }

  //char a[] = "hello";
  //a[0] = 'X';

  //char * p =  "world";
  //p[0] = 'Y';


}