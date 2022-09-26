
#include <iostream>

using namespace std;

void char2Hex(char c) // 将字符以16进制表示
{
  char ch = c / 0x10 + '0';
  if ( ch > '9' )
    ch += ('A' - '9' - 1);

  char cl = c % 0x10 + '0';
  if ( cl > '9' )
    cl += ('A' - '9' - 1);

  cout << ch << cl << " ";
}

void hexchar()
{
  char str[] = "\10\11\12ABCDEFGHIJK\145";
  for ( auto  c : str)
  {
    char2Hex(c);
  }
  cout << endl;


  for ( size_t i = 0; i< sizeof (str);i++)
  {
    char2Hex(str[i]);
  }

  cout << endl;
}