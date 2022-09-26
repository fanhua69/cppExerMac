

#include <iostream>
using namespace std;

extern "C"
{
// every object of type sse_t will be aligned to 16-byte boundary
struct alignas(16) sse_t
{
  char c1;
  int sse_data[4];
  char c2;
};

struct e
{};

struct E
{
  int a;
  double b;
  float c;
};
struct F
{
  int i;
  double d;
  unsigned bf1:10;
  int bf2:25;
  int bf3:1;
  int bf4:9;
  int i2;
  char c1,c2;
  std::string s;
};

// the array "cacheline" will be aligned to 128-byte boundary
alignas(128) char cacheline[128];

void alignment2()
{
  cout << sizeof(sse_t) << endl;

  F f;
  memset(&f,0,sizeof(F));

  f.i = 1;
  f.d = 2;
  f.bf1 = 3;
  f.bf2 = 4;
  f.bf3 = 1;
  f.bf4 = 2;
  f.i2 = 3;
  f.c1 = 'A';
  f.c2 ='B';

  cout << sizeof(cacheline) << endl;
  cout << sizeof(e) <<endl;
  cout << sizeof(F) << endl;
}
}