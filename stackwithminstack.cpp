

#include <stack>

template <class T>
class CMyStackStack
{
  CMyStackStack (){};
  void push (const T &v)
  {
    m_stack.push(v);

    if(m_minStack.empty())
    {
      m_minStack.push(v);
    }
    else if(v <= m_minStack.top())
    {
      m_minStack.push(v);
    }
  }

  T top()
  {
    return m_stack.top();
  }

  T getMin()
  {
    return m_minStack.top();
  }

  void pop()
  {
    if(m_stack.size() == 0)
    {
      return;
    }

    if( m_stack.top() == m_minStack.top())
    {
      m_minStack.pop();
    }

    m_stack.pop();
  }
private:
  std::stack<T> m_stack;
  std::stack<T> m_minStack;
};