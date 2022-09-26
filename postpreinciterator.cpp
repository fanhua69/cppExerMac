

// -Post and Pre increments in C++ in the context of iterators.

class testInc
{
public:
  testInc(int n)
  {
    m_data = n;
  }

  testInc & operator ++()
  {
    m_data++;
    return *this;
  }

  testInc operator ++(int)
  {
    testInc t(m_data);
    m_data++;
    return t;
  }
private:
  int m_data;
};

void testIncMain()
{
  testInc q(1);

  testInc a = q++;
  testInc b= ++q;


}