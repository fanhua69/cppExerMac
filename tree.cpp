
#include <iostream>
#include <stack>

#include "tree.h"

using namespace std;

template <class T>
CTreeNode<T>::CTreeNode (const T& value)
{
  m_dValue = value;
  m_bVisited = false;
}

template <class T>
CTreeNode<T>::~CTreeNode()
{
  delete m_pChildLeft;
  delete m_pChildRight;
}

template <class T>
void CTreeNode<T>::reset()
{
  m_bVisited = false;
  if(m_pChildLeft)
    m_pChildLeft->reset();

  if ( m_pChildRight )
    m_pChildRight->reset();
}

template <class T>
void CTreeNode<T>::addLeftChild(CTreeNode *node)
{
  if ( m_pChildLeft )
  {
    delete m_pChildLeft;
    m_pChildLeft = NULL;
  }

  m_pChildLeft = node;
}

template <class T>
void CTreeNode<T>::addRightChild(CTreeNode *node)
{
  if ( m_pChildRight )
  {
    delete m_pChildRight;
    m_pChildRight = NULL;
  }

  m_pChildRight = node;
}

template <class T>
bool CTreeNode<T>::findnode(const T & v)
{
  if ( m_dValue == v )
  {
    return true;
  }

  if ( m_pChildLeft && m_pChildLeft->findnode(v) )
  {
    return true;
  }

  if ( m_pChildRight && m_pChildRight->findnode(v) )
  {
    return true;
  }
  
  return false;
}

template < class T>
void traversal(CTreeNode<T> *node)
{
  if ( node )
  {
    cout << node->m_dValue << endl;
  }

  if ( node->m_pChildLeft )
  {
    traversal(node->m_pChildLeft);
  }

  if ( node->m_pChildRight )
  {
    traversal(node->m_pChildRight);
  }
}

template <class T>
void DFS_without_recursion(CTreeNode<T> *head)
{
  CTreeNode *temp = head;

  while ( temp && !temp->m_bVisited )
  {
    if ( temp->m_pChildLeft && !temp->m_pChildLeft->m_bVisited )
    {
      temp = temp->m_pChildLeft;
    }
    else if ( temp->m_pChildRight && !temp->m_pChildRight->m_bVisited )
    {
      temp = temp->m_pChildRight;
    }
    else
    {
      cout << temp->m_dValue << endl;
      temp->m_bVisited = 1;
      temp = head;
    }
  }
}

template < class T>
void depthfirst_no_incursive(CTreeNode<T> *node)
{
  std::stack <CTreeNode*> stack_tree;
  if(!node)
  {
    return;
  }

  if ( node )
  {
    stack_tree.push(node);
  }

  while(stack_tree.size () > 0)
  {
    node = stack_tree.top();
    cout << node->m_dValue << endl;

    stack_tree.pop();

    if(node->m_pChildLeft)
    {
      stack_tree.push (node->m_pChildLeft);
    }

    if ( node->m_pChildRight )
    {
      stack_tree.push(node->m_pChildRight);
    }
  }
}

template <class T>
void breadthfirst_no_incursive(CTreeNode<T> *node)
{
  std::deque<CTreeNode*> q;
  if ( !node )
  {
    return;
  }

  if ( node )
  {
    q.push_back(node);
  }

  while ( q.size() > 0 )
  {
    node = q.front();
    cout << node->m_dValue << endl;

    q.pop_front();

    if ( node->m_pChildLeft )
    {
      q.push_back(node->m_pChildLeft);
    }

    if ( node->m_pChildRight )
    {
      q.push_back(node->m_pChildRight);
    }
  }
}


void tree()
{
  CTreeNode<int> *root = new CTreeNode<int>(1);
  CTreeNode<int> *left = new CTreeNode<int>(2);
  CTreeNode<int> *right = new CTreeNode<int>(3);

  root->addLeftChild (left);
  root->addRightChild (right);

  CTreeNode<int> *left1 = new CTreeNode<int>(4);
  CTreeNode<int> *right1 = new CTreeNode<int>(5);
  left->addLeftChild (left1);
  left->addRightChild(right1);

  CTreeNode<int> *left2 = new CTreeNode<int>(6);
  CTreeNode<int> *right2 = new CTreeNode<int>(7);
  right->addLeftChild(left2);
  right->addRightChild(right2);

  //traversal(root);

  // breadthfirst_no_incursive(root);
  bool b = root->findnode(8);


  delete root;


}


