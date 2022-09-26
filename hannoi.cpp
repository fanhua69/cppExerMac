

#include <iostream>
#include <set>
#include <utility>

using namespace std;

#include "iostream"

struct ssss
{
  bool operator() (const char *s1, const char *s2) const
  {
    return strcmp(s1, s2) < 0;
  }

  int m_a ;
  double m_b;
};

class ssssI
{
public:
  bool operator() (int a, int b) const
  {
    return a > b;
  }

  int m;
  double ml;
};


void map();

int sssss ;
double ad;

ssssI aa;

string foo()
{
  return "AAA";
};

void bar(string & s)
{
  s = s+"qwe";
}

int  nRowOrder(int argc, char **argv)
{
  map();

  bar(foo());

  const char *c = "test";
  char c1 = 'a';
  char c2= 'A';
  char c3 = 127;
  unsigned char c4 = '\a';
  char c5 = '\b';
  char c6 = '\f';
  char c7 = '\n';
  char c8 = '\t';
  char c9 = '\v';
  char c10 = '\xE';

  int mm;

  int &mmm = mm;
  int &&mmmm = 10;
  mm = mmmm;

  mmmm = 1234;

  int * p = &mmm;

  std::move(mmmm);


  typedef std::set<int> SETS;

  SETS mset;
  mset.insert (3);
  mset.insert(6);
  mset.insert(8);
  mset.insert(18);
  mset.insert(28);

  SETS::iterator it = mset.find(6);

  int n = *it;

  std::set<const char*, ssss> s2; //(strLess);
  s2.insert("werew3");
  s2.insert("werew2");

  SETS s3(mset);

  int a[] = { 13, 32, 19 };
  std::set <int,ssssI> s4;
  s4.insert(1);
  s4.insert(11);
  s4.insert(100);

  s4.erase (11);
  s4.clear ();


  return 0;


}
