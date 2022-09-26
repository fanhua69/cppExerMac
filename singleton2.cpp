

#define NULL 0
class Singleton
{
private:
  static Singleton* m_pInstance;
  Singleton()
  {
  };

  ~Singleton()
  {
    m_pInstance = NULL;
  }

public:

  static Singleton* GetInstance()
  {
    if ( m_pInstance == NULL )
    {
      m_pInstance = new Singleton();
    }
    return m_pInstance;
  }

  static void ResetInstance()
  {
    if(m_pInstance != NULL)
    {
      delete m_pInstance;
      m_pInstance = NULL;
    }
  }
};

Singleton*  Singleton::m_pInstance = NULL;

void singleton2()
{
  Singleton* pInstance = Singleton::GetInstance();
  Singleton::ResetInstance ();
}