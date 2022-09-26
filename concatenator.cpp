

#define A(x) A##x
#define B(x) #@x
#define C(x) #x

void concatenator()
{
  char c = B(3);
  auto  d = C(12323);
  int A1 = 123;
  int A2 = 456;

  int B1 = A(1);
  int B2 = A(2);
  

  decltype(d) e;

}