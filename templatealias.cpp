
#include <map>
#include <string>
using namespace std;

// template alias:
template <class T> class A
{
};

template <typename T> using B = A<T>;


B<int> hh;


// type alias:
typedef unsigned int uint_t;


void func(uint_t a)
{
  int c = a;
}

typedef std::map<std::string, int> map_int_t;

// ...  

typedef std::map<std::string, std::string> map_str_t;

using map_s_f = std::map<std::string,float>;

void templatealias()
{
  map_str_t t;
  t["a"] = "b";
  string s = t["a"];

  char * ss = "abc";
  int n = strlen(ss);
}