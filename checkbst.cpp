


#include "tree.h"

template <class T>
bool checkbst(CTreeNode<T> *root)
{
  if(!root || !root->m_pChildLeft && !root->m_pChildRight)
  {
    return true;
  }

  if( root->m_pChildLeft && root->m_pChildRight)
  {
    if(root->m_pChildLeft->m_dValue > root->m_dValue
       || root->m_pChildRight->m_dValue < root->m_dValue)
    {
      return false;
    }
  }

  if ( !checkbst(root->m_pChildLeft) ||
       !checkbst(root->m_pChildRight) )
  {
    return false;
  }

  return true;
}

void checkbstmain()
{
  CTreeNode<int> *root = new CTreeNode<int>(20);
  root->addLeftChild(new CTreeNode<int>(10));
  root->addRightChild(new CTreeNode<int>(30));

  bool b = checkbst(root);

  delete root;

}