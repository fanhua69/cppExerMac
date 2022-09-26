
#include <iostream>

using namespace std;


class A2
{
public:
  A2()
  {
    m = 12314;
  };

  int t(int, double)
  {
    return m;
  };
  
  int m = 1234;
};


double tt(int,float){return 1234;}

void nullptrmain()
{
  string str = "wqrewqrwer";
  const char * pc = str.c_str();
  if(pc == nullptr)
  {
    int mm = 0;
  }
  else
  {
    cout << pc << endl;
  }



  int (A2::*pmf )(int, double) = &(A2::t);
  A2 a;
  int n = (a.*pmf)(1,2);

  double (*p)(int,float) = &tt;

  double d = (*p)(1,2);

  std::nullptr_t t,t1;
  t = nullptr;



      


}