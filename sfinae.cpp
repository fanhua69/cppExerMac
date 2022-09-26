
#include <string>
using namespace std;

template<typename T>
struct HasToStringFunction
{
  typedef struct
  {
    char a[2];
  } Yes;

  typedef struct
  {
    char a[1];
  } No;

  template<typename FooType, char* (FooType::*)()>
  struct FuncMatcher
  {
  };

  template<typename FooType>
  static Yes Tester(FuncMatcher<FooType, &FooType::ToString>*);

  template<typename FooType>
  static No Tester(...);

  enum
  {
    Result = sizeof(Tester<T>(nullptr)) == sizeof(Yes)
  };
};

static char* (*f)() = []()->char*
{
  return NULL;
};

char * ff()
{
  return NULL;
}

void sfinae()
{
  //HasToStringFunction<int>::FuncMatcher<string,ff> a;
  //bool a_has_tostring = HasToStringFunction<A>::Result;   // Tru
  //bool b_has_tostring = HasToStringFunction<B>::Result;   // False
}