
#include "constMember.h"
#include "string.h"
#include <csignal>

int constMember::m_sData = 2;

constMember::constMember():m_data(1)
{
  char *s = "1234";
  int n = sizeof(s);

  m_string = NULL;

}

constMember::~constMember()
{
  if(m_string != NULL)
  {
    delete m_string;
  }
}

constMember::constMember(const constMember &other)
{
  int length = strlen(other.m_string);
  m_string = new char [length + 1];
  strcpy_s(m_string,length, other.m_string);
}

constMember & constMember::operator = (const constMember &other)
{
  if(this == &other)
  {
    return *this;
  }

  //
  delete []m_string;

  //
  int length = strlen(other.m_string);
  m_string = new char[length+1];

  strcpy_s(m_string, length, other.m_string);

  //
  return *this;
}


#include <iostream>

using namespace std;

void myhandler(int NUM)
{
  cout << NUM << endl;
  exit(NUM);
}

void constMemberMain()
{
  constMember a;
  constMember b;

  cout << a.m_data << endl;
  cout << b.m_data << endl;

  cout << &a.m_data << endl;
  cout << &b.m_data << endl;

  cout << a.m_sData << endl;
  cout << b.m_sData << endl;

  cout << &a.m_sData << endl;
  cout << &b.m_sData << endl;

  signal(SIGINT, myhandler);
  while(true)
  {
    cout << "going to sleep" <<endl;
    // sleep(1);
  }
}

