

struct bit alignas(1)
{
  unsigned dd : 1;
};

struct bits
{
  bit a[16];
  //unsigned a: 1;
  //unsigned b: 1;
  //unsigned c: 1;
  //unsigned d: 1;
  //unsigned e: 1;
  //unsigned f: 1;
  //unsigned g: 1;
  //unsigned h: 1;
};

void onescomplementry()
{
  unsigned short int a = 1;
  unsigned short int b = ~a;
  

  bits * pa = (bits*)&a;
  bits * pb = (bits*)&b;

}