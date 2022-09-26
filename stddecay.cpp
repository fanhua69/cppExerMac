
#include <stdlib.h>
#include <iostream>
#include <type_traits>

template<typename T>
void typeCheck(T data);

int stddecay()
{
  int a = 1;
  const int& b = a;
  int& c = a;
  int d[12];

  typeCheck<int>(a);        //int type
  typeCheck<const int&>(b);//other type
  typeCheck<int &>(c);        //other type
  typeCheck<const int&>(d[7]);//other type
  typeCheck(8);                //int type
  return 0;
}

template<typename T>
void typeCheck(T data)
{
  if ( std::is_same<T, int &>::value )
  {
    std::cout << "int type" << std::endl;
  }
  else if ( std::is_same<std::decay<T>::type, std::string>::value )
  {
    std::cout << "string type" << std::endl;
  }
  else
  {
    std::cout << "other type" <<std::endl;
  }
}