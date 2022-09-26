
class ut
{
public:
  ut(){f = 0;}
  ut(int a)
  {
    f = a;
  }
  float f;
};

ut operator "" _ut(unsigned long long  a)
{
  return ut(a);
}

static ut operator "" _ut(char  aaaa123)
{
  ut b1234;
  b1234.f = aaaa123; 
  return b1234;
}

void userdefinedliterals()
{
  ut t = 12432432_ut;
  ut t2 = 'b'_ut;
}