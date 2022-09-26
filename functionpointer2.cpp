

int calc(double a, int b, float c)
{
  return (int)(a*b*c);
}



void functionpointer2()
{
  int(*pf)(double, int, float);
  pf = &calc;
  int n = pf(1,2,3);
}


