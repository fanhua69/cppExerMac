
#include <iostream>
using namespace std;

class HasPtrMem
{
public:
  HasPtrMem() : d(new int(0))
  {
    cout << "Construct: " << ++n_cstr << endl;
  }

  HasPtrMem(const HasPtrMem &rhs) : d(new int(*rhs.d))
  {
    cout << "Copy Construct: " << ++n_cpstr << endl;
  }

  ~HasPtrMem()
  {
    delete d;
    d = nullptr;
    cout << "Destruct: " << ++n_dstr << endl;
  }

  int *d;
  static int n_cstr;
  static int n_dstr;
  static int n_cpstr;
};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cpstr = 0;

HasPtrMem getTemp()
{
  HasPtrMem a;
  return a;
}

// Return Value Optimization
int RVO()
{
  HasPtrMem a = getTemp();
  return 0;
}