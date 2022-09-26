
#include <algorithm>
#include <vector>


void func4(std::vector<double>& v)
{
  std::transform(v.begin(), v.end(), v.begin(),
                 [](double d)
  {
    return d*2;
  }
  );
}

void stdtransform()
{
  std::vector<double>b {1,2,3,4,6};
  func4(b);

}