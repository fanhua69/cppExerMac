
#ifndef constM_h
#define constM_h

class constMember
{
public:
  constMember();
  virtual ~constMember();
  constMember(const constMember &a);
  constMember & operator = (const constMember &other);

public:
  const int m_data = 1;
  static int m_sData;
  int mm = 2;
  static const int nn = 3;
  char * m_string;
};

#endif