

#define A(x) 2##x
#define B(x) #@x
#define C(x) #x

//A(1) == 21
//B(1) == '1'
//C(1) == "1"

//TCHAR tStr[] = _T("t code");  //_T宏的作用就是转换成TCHAR。

#define SQUARE(a) ((a)*(a))

#define MIN(A,B) ((A)<(B)?(A):(B))

void macro()
{
  int a = 5;
  int b;
  b= SQUARE(a++);

  int  c1 = A(1);
  char c2 = B(1);
  char c3[] = C(1);
}