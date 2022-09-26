


#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool com(const string &a,const string &b)
{
  char ca = a.back ();
  char cb = b.back();

  return ca < cb;
}

string foou(){return string("qwq");};
void baur(string & s)
{
  s = "dsfsd";
};

struct aaaa
{
public:
  aaaa()//:aaa1(*this)
  {
  }

  ~aaaa()
  {
    int m = 0;
  }
  aaaa(int a)//:aaa1(*this)
  {
    this->a = a;
  }
  void t()
  {
    int m = 0;
    *this = 23;
  }

  static int m_s;
  int a;
};

int aaaa::m_s = 100;

void pair()
{
  baur(foou());
  aaaa *a = new aaaa;
  a->t();
  a->m_s = 10;

  delete a;

  bool(*f)(const string &, const string &) = com;
  std::map <char ,std::vector<int>> m;
  string s = "acxvtreqthshhgfjhgdjfdcsa dsafqerekwqvrew qrewxqre wqrew";
  for(unsigned int i=0 ;i < s.length ();i++)
  {
    char c = s[i];
    std::vector<int> &v = m[c];
    v.push_back (i);
  }

  std::map<char,std::vector<int>>::iterator it = m.begin ();
  
  char minc;
  int minOrder = s.size ();
  while(it != m.end())
  {
    std::vector<int> &v =it->second;
    if(v.size () == 1)
    {
      if(v[0] < minOrder)
      {
        minOrder = v[0];
        minc = it->first;
      }
    }
    it++;
  }


  
}