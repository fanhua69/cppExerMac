


#include <iostream>
#include <map>
#include <utility>

using namespace std;

#include "iostream"

void  map()
{
  typedef std::map<int, string> MAPS;

  std::pair<int, string> p(1, "WEW");
  p.first = 10;
  p.second = "aasfdfd";


  MAPS students;
  students.insert(p);
  students.insert(std::pair<int, string>(1, "FanHua"));
  students[6] = "ZeZhen";
  students[6] = "ZeZhen2";
  students[9] = "Rehong";
  students[14] = "FanChuan";

  MAPS::iterator it = students.find(15);
  if ( it != students.end() )
  {
    string s = it->second;
    int n = it->first;
  }

  int c = students.count(7);

  int nn = students.size();

  MAPS::iterator it2;
  for ( it2 = students.begin();
       it2 != students.end();
       it2++ )
  {
    int m = it2->first;
    string s = it2->second;
  }

  MAPS::reverse_iterator itr;
  for ( itr = students.rbegin();
       itr != students.rend();
       itr++ )
  {
    int nnn = itr->first;
    string sss = itr->second;
  }

  students.erase(6);
  students.erase(7);

  nn = students.size();

  students.clear();

}

int testInt;
