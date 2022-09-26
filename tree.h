
#ifndef tree_h
#define tree_h

template<class T>
class CTreeNode
{
public:
  CTreeNode(){};
  CTreeNode(const T &value);
  ~CTreeNode();
  void reset();
  void addLeftChild(CTreeNode<T> *node);
  void addRightChild(CTreeNode<T> *node);
  bool findnode(const T &v);

  bool        m_bVisited;
  T           m_dValue;
  CTreeNode * m_pChildLeft;
  CTreeNode * m_pChildRight;
};


#endif