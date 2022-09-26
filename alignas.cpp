
#include <iostream>
using namespace std;
#pragma pack(1)

struct alignas(16) ColorVector
{
  double r;
  char   g;
  double b;
  double a;
};

template <typename T>
class FixedCapacityArray
{
public:
  //void push_back(T t);

  float f;
  char alignas (T) data[1024] = {0};

};

void alignasmain()
{
  FixedCapacityArray<char> ac;

  cout << "alignas of char:" << alignof(char) << endl;
  cout << "alignas of arrCh: " << alignof(FixedCapacityArray<char>) << endl;
  cout << "alignas of arrCh.data: " << ((char*)(&ac.data) - (char*)(&ac)) << endl;



  FixedCapacityArray <ColorVector> av;
  alignment_of<ColorVector> a;
  cout << "alignas of ColorVector:" <<a << endl;
  cout << "alignas of arrCV.data: " << alignof(FixedCapacityArray<ColorVector>) << endl;
  cout << "alignas of arrCh.data: " << ((char*)(&av.data) - (char*)(&av)) << endl;
  cout << "alignas of arrCh.data 1: " << ((char*)(&av.data[1]) - (char*)(&av.data[0])) << endl;
}
