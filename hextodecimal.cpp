
#include <iostream>

using namespace std;

int hextodecimal(const char *s)
{
  if ( s == NULL )
  {
    return 0;
  }

  const char *p = s;

  while(*p == '0')
  {
    p++;
  }

  char c;
  int dec= 0;
  while(c = *p++)
  {
    dec <<= 4;

    if(c >= '0' && c<='9')
    {
      dec += c - '0';
    }
    else if(c >= 'A' && c<= 'F')
    {
      dec += c - 'A' + 10;
    }
    else if(c >= 'a' && c <= 'f')
    {
      dec += c - 'a' + 10;
    }
    else
    {
      return -1;
    }
  }

  return dec;
}

void hextodecimalmain()
{
  char * s = "100F";
  int n = hextodecimal(s);
}