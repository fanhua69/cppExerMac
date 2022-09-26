
#include <iostream>
#include <list>

using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};

class Binary_Tree
{
  Node *root;
  list<list<Node*> > level(Node*);

public:
  Binary_Tree()
  {
    root = NULL;
  }

  void insert(int element);
  void in_order_search();
  void in_order_search(Node *node);

  void Layer_Traver();
  void Layer_Traver(Node * root);


  list<list<Node*> > level();
};

void Binary_Tree::in_order_search()
{
  in_order_search(root);
  cout << endl;
}

void Binary_Tree::in_order_search(Node *node)
{
  if(node == nullptr)
  {
    return;
  }

  if(node->left)
  {
    in_order_search (node->left);
  }

  cout << node->data << ",";

  if ( node->right)
  {
    in_order_search(node->right);
  }
}

void Binary_Tree::Layer_Traver()
{
  Layer_Traver (root);
  cout << "." << endl;
}

struct NodeOrder
{
  Node *pNode;
  int   nLevel;
  NodeOrder()
  {
    pNode= NULL;
    nLevel=-1;
  }
};


void Binary_Tree::Layer_Traver(Node * root)
{
  if ( root == nullptr )
  {
    return;
  }

  int head = 0, tail = 0;
  NodeOrder que[100];

  que[head].pNode = root;
  que[head].nLevel = 0;
  tail++;
  
  while ( head < tail )
  {
    Node *node = que[head].pNode;
    int nHeadLevel = que[head].nLevel;

    if ( node->left != NULL )//left
    {
      que[tail].pNode = node->left;
      que[tail].nLevel = nHeadLevel+1;
      tail++;
    }
    if ( node->right != NULL )//right
    {
      que[tail].pNode = node->right;
      que[tail].nLevel = nHeadLevel + 1;
      tail++;
    }

    cout << node->data << ",";
    cout << nHeadLevel << "; ";

    head++;
  }
  return;
}


void Binary_Tree::insert(int ele)
{
  Node *node = new Node(ele);
  if ( root == NULL )
  {
    root = node;
    return;
  }

  Node* temp = root;
  while ( temp != NULL )
  {
    if ( ele > temp->data )
    {
      if ( temp->right != NULL )
      {
        temp = temp->right;
      }
      else
      {
        temp->right = node;
        return;
      }
    }
    else
    {
      if ( temp->left != NULL )
      {
        temp = temp->left;
      }
      else
      {
        temp->left = node;
        return;
      }
    }
  }
}

list<list<Node*> > Binary_Tree::level()
{
  return level(root);
}


list<list<Node*> > Binary_Tree::level(Node* node)
{
  list<Node*> listCurrent, listParent;
  list<list<Node*> > listListResult;

  list<Node*>::iterator itr;
  if ( node != NULL )
  {
    listCurrent.push_back(node);
  }

  while ( listCurrent.size() > 0 )
  {
    listListResult.push_back(listCurrent);
    listParent = listCurrent;

    listCurrent.clear();
    itr = listParent.begin();
    while ( itr != listParent.end() )
    {
      if ( (*itr)->left != NULL )
      {
        listCurrent.push_back((*itr)->left);
      }

      if ( (*itr)->right != NULL )
      {
        listCurrent.push_back((*itr)->right);
      }

      itr++;
    }
  }

  return listListResult;
}

int depthlevellist()
{
  list<list<Node*> >l;
  list<list<Node*> >::iterator itr;
  list<Node*>::iterator itr1;

  Binary_Tree bt;
  bt.insert(7);
  bt.insert(3);
  bt.insert(2);
  bt.insert(4);
  bt.insert(1);
  bt.insert(5);
  bt.insert(9);
  bt.insert(8);
  bt.insert(10);
  bt.insert(11);
  bt.insert(12);
  bt.insert(13);

  bt.Layer_Traver ();

  bt.in_order_search ();
  l = bt.level();

  itr = l.begin();
  while ( itr != l.end() )
  {

    itr1 = (*itr).begin();
    while ( itr1 != (*itr).end() )
    {
      cout << (*itr1)->data << " ";
      itr1++;
    }
    cout << endl;
    itr++;

  }

  return 0;
}