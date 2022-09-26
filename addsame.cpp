

#include <unordered_map>
#include <map>
#include <stdio.h>
#include <fstream>

#include <iostream>
#include <fstream>
using namespace std;

typedef std::map<int,int> DATAMAP;


bool addsame(const char *fileIn, const char *fileOut)
{
  ifstream fin;
  fin.open(fileIn);
  if(!fin.is_open())
  {
    cout <<"file not found:" << fileIn <<endl;
    return false;
  }

  char time[10];
  double price;
  int priceInt;
  int qty;
  int z;
  char buy[10];

  DATAMAP data;

  while(!fin.eof())
  {
    fin >> time >> price >> qty >> z >> buy  ;
    price *= 100;
    priceInt = price;
    DATAMAP::iterator it = data.find(price);
    if(it == data.end())
    {
      std::pair<DATAMAP::iterator,bool> r = data.insert(make_pair(price,qty));
      if(!r.second)
      {
        break;
      }
    }
    else
    {
      it->second += qty;
    }
    cout << time << " " << price << " " << qty << " " << z << " " << buy << endl;
  }
  fin.close();


  DATAMAP data2;
  DATAMAP::iterator it = data.begin();
  while(it!=data.end())
  {
    cout << it->first << " " << it->second << endl;
    data2.insert(std::make_pair(it->second,it->first));
    it++;
  }

  cout << endl << endl << endl << endl;



  ofstream fo;
  fo.open(fileOut);
  if(fo.is_open())
  {
    it = data.begin();
    while(it!=data.end())
    {
      cout << it->first/100.0 << "    " << it ->second << endl;
      fo << it->first /100.0 << "    " << it ->second << endl;
      it++;
    }
  }
  fo.close();

  return true;
}