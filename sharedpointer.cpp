


#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

// -Implement a class that performs like a shared pointer
// (similar to boost::shared_ptr or std::shared_ptr from C++11)

template <class T>
class sharedPtr
{
public:
  sharedPtr(T *p): m_pPointee(p)
  {
    m_mapPointers[p]++;
  }

  sharedPtr(const sharedPtr &o)
  {
    m_pPointee = o.m_pPointee;
    m_mapPointers[m_pPointee] ++;
  }

  sharedPtr():m_pPointee(NULL)
  {
  }

  ~sharedPtr()
  {
    if(m_pPointee != NULL)
    {
      m_mapPointers[m_pPointee]--;
      if(m_mapPointers[m_pPointee] == 0)
      {
        delete m_pPointee;
      }
    }
  }

  sharedPtr & operator = (const sharedPtr &o)
  {
    if(this == &o)
    {
      return *this;
    }

    m_pPointee = o.m_pPointee;
    m_mapPointers[m_pPointee]++;

    return *this;
  }

  T* operator ->()
  {
    return m_pPointee;
  }

  int use_count()
  {
    return m_mapPointers[m_pPointee];
  }

public:
  T * m_pPointee;
  static std::unordered_map<T*, int> m_mapPointers;
};

template <class T>
std::unordered_map<T*, int> sharedPtr<T>::m_mapPointers;

class CLeader;
class CMember;

class CLeader
{
public:
  CLeader()
  {
    cout << "CLeader::CLeader()" << endl;
  }
  ~CLeader()
  {
    cout << "CLeader:;~CLeader() " << endl;
  }

  sharedPtr<CMember> member;
};

class CMember
{
public:
  CMember()
  {
    cout << "CMember::CMember()" << endl;
  }
  ~CMember()
  {
    cout << "CMember::~CMember() " << endl;
  }

  sharedPtr<CLeader> leader;
};

void SmartPointerMain()
{
  {
    cout << "TestCrossReference<<<" << endl;
    sharedPtr <CLeader> ptrleader(new CLeader);
    sharedPtr <CMember> ptrmember(new CMember);

    ptrleader->member = ptrmember;
    ptrmember->leader = ptrleader;

    cout << "  ptrleader.use_count: " << ptrleader.use_count() << endl;
    cout << "  ptrmember.use_count: " << ptrmember.use_count() << endl;
  }

  auto it = sharedPtr<CLeader>::m_mapPointers.begin();
  while(it != sharedPtr<CLeader>::m_mapPointers.end())
  {
    int n = it->second;
    it++;
  }

}


