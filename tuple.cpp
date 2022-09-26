

#include <iostream>
#include <string>
#include <algorithm>

#include <tuple>
using namespace std;


void tuplemain()
{
  std::tuple < int, char,double> tup = { 1,'c',2.3};

  int n;
  char c;
  double d;
  int nn;

  //int n = std::get<0>(tup);
  //char c = std::get<1>(tup);
  //double d = std::get<2> (tup);

  //std::tie (n,c,d, nn) ;;// = tup;
  // auto [ii,ic,id ] = tup; C++17


}