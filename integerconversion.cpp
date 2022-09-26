
#include <stdio.h>
#include <iostream>

void integerconversin(void)
{
  unsigned int a = 6;
  int b = -20;

  unsigned int c = a+b;

  ((a + b) > 6) ? puts("> 6") : puts("<= 6");

  char c1 = -2;
  unsigned char c2 = 1;

  unsigned char nm = (unsigned char)(*(&c1));

  char c3 = c1 + c2;

  (c1 + c2 >= 0)? puts(">=0"): puts("<0");

  unsigned int i = 3;
  std::cout << (i * -1)<< std::endl;

  int nn = i;
  int nnn = nn * -1;

  char *ptr;
  if ( (ptr = (char *)malloc(0)) == NULL )
    puts("Got a null pointer");
  else
    puts("Got a valid pointer");

  std::cout<<nnn<< std::endl;

  int a1 = 5, b1 = 7, c11;
  c11 = a1+++b1;


  char *p1 = "name";
  char *p2;
  p2 = (char*)malloc(20);
  char *p3 = p2;
  memset(p2, 0, 20);
  while ( *p2++ = *p1++ )
  {
    int mm = 0;
  };
  printf("%s\n", p2);

  char *ptr9 = "Cisco Systems";
  char *p10 = ptr9;
  char p110 = *ptr9++;
  *ptr9++; printf(":%s\n", ptr9);
  ptr9++;
  printf(":%s\n", ptr9);
  printf(":%s\n", p10);


  char s1[] = "Cisco";
  char s2[] = "systems";
  printf("%s\n", s1);

}
