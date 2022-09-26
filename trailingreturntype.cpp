
class trailtype
{
public:
  trailtype()
  {
    m_a =1;
    m_b = 2;
  }
  
  int m_a;
  int m_b;

  trailtype operator * (trailtype b)
  {
    return trailtype();
  }

  trailtype operator * ()
  {
    return trailtype();
  }

};

template < class T>
auto Mul(T a, T b)->decltype(a*b)
{
  trailtype f = *a;
  return a*b;
}

void trailingreturntype()
{
  trailtype a,b;
  trailtype c= Mul (a,b);
}