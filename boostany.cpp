
//#include <boost\variant\any.hpp> 
#include <boost\variant.hpp>
#include <string> 
#include <iostream>
#include <boost\atomic\atomic.hpp>
boost::atomic<int> a;
void boostany()
{
  boost::variant <int, std::string> a;
  a = 12;
  std::cout << boost::get <int> (a) << std::endl;
  
  a = std::string("Hello, world!");
  std::cout << boost::get <std::string> (a) << std::endl;
 
  a = 3.1;
  std::cout << boost::get <std::string> (a) << std::endl;
}