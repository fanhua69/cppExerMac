
#include <stack>

using namespace std;

template < class T >
class CMyStack
{
  CMyStack()
  {
    m_minValue = 0;
  }

  void push(const T& v)
  {
    if(size() == 0)
    {
      m_minValue = v;
      m_stack.push(v);
      return;
    }

    if(v >= m_minValue)
    {
      m_stack.push(v);
      return;
    }

    T nv = 2 * v - m_minValue;
    m_minValue = v;
    stack::push(nv);
  }

  T peek()
  {
    if(m_stack.empty())
    {
      return T();
    }

    T t = m_stack.top();
    if(t > m_minValue)
    {
      return t;
    }
    else
    {
      return m_minValue;
    }
  }

  void pop()
  {
    ASSERT(size()>0);

    T v = m_stack.pop();
    if(v >= m_minValue)
    {
      return;
    }

    m_minValue  = 2 * v - m_minValue;
    return;
  }

  T getMin()
  {
    if(m_stack.empty())
    {
      cout << "Stack is empty" << endl;
      return T();
    }

    return m_minValue;
  }

private:
  T m_minValue;
  std::stack m_stack;
};