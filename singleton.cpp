

#include <memory>
#include <mutex>

class CSingleton
{
public:
  virtual ~CSingleton(){};
  static CSingleton& GetInstance();

private:
  static std::unique_ptr<CSingleton> m_instance;
  static std::once_flag m_onceFlag;
  CSingleton(void) = default;
  CSingleton(const CSingleton& src);
  CSingleton& operator=(const CSingleton& rhs);
};

std::unique_ptr<CSingleton> CSingleton::m_instance;
std::once_flag CSingleton::m_onceFlag;

CSingleton& CSingleton::GetInstance()
{
  std::call_once(m_onceFlag,[]()
  {
    m_instance.reset(new CSingleton);
  });

  return *m_instance.get();
}

void singleton()
{
  CSingleton &p = CSingleton::GetInstance ();
  CSingleton &p1 = CSingleton::GetInstance();

}
