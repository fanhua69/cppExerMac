
#include <iostream>

/*
* Complete the function below.
*/

//For your reference, the following has already been included:
using namespace std;

class DoubleLinkedListNode
{
public:
  int val;
  DoubleLinkedListNode *prev, *next;

  DoubleLinkedListNode(int node_value)
  {
    val = node_value;
    prev = next = NULL;
  }
};


DoubleLinkedListNode* Insert(DoubleLinkedListNode* node, int value)
{
  // Create the new node with the given value:
  DoubleLinkedListNode *newNode = new DoubleLinkedListNode(value);
  if(!newNode)
  {
    return NULL;
  }

  newNode->prev = NULL;
  newNode->next = NULL;

  // if no node exists:
  if(node == NULL)
  {
  }

  // Only one node exists:
  else if(node->next == NULL && node ->prev == NULL)
  {
    node->next = newNode;
    node->prev = newNode;
    newNode->next = node;
    newNode->prev = node;
  }

  // insert the new node into the list:
  else
  {
    DoubleLinkedListNode *currentNode = node;
    DoubleLinkedListNode *nextNode    = node->next;
    bool passedHead = false;
    while( true)
    {
      if(   currentNode->val <= value && nextNode->val >= value ||
          ( currentNode->val > nextNode->val && (value <= nextNode->val || value >= currentNode->val)) ||
          (passedHead && currentNode == node))
      {
        currentNode ->next = newNode;
        newNode->prev      = currentNode;

        newNode->next      = nextNode;
        nextNode->prev     = newNode;
        break;
      }
      else
      {
        currentNode        = nextNode;
        nextNode           = nextNode->next;
        if(!nextNode)
        {
          break;
        }
        passedHead = true;
      }
    }
  }

  // find the smallest node:
  DoubleLinkedListNode *startNode   = NULL;
  DoubleLinkedListNode *currentNode = NULL;
  if(newNode ->next == NULL)
  {
    startNode = newNode;
  }
  else
  {
    currentNode = newNode;
    while ( true )
    {
      if ( !currentNode || !currentNode->next || currentNode->val > currentNode->next->val )
      {
        break;
      }
      else
      {
        currentNode = currentNode->next;
      }

      if(currentNode == newNode)
      {
        break;
      }
    }

    startNode = currentNode->next;
  }


  // print the list forwardly:
  //std::cout << "Forward: " << std::endl;
  currentNode = startNode;
  while ( true )
  {
    //cout << currentNode ->val << " ";
    currentNode = currentNode->next;
    if(!currentNode  || currentNode == startNode)
    {
      break;
    }
  }
  //std::cout << std::endl;

  // print the list backwardly:
  //std::cout << "Backward: " << std::endl;
  if( startNode && startNode->prev )
  {
    startNode = startNode->prev;
  }

  currentNode = startNode;

  while ( true )
  {
   // cout << currentNode->val << " ";
    currentNode = currentNode->prev;
    if ( !currentNode  || currentNode == startNode )
    {
      break;
    }
  }
  //std::cout << std::endl;

  // Return the new inserted node:`
  return newNode;

}

void doubleListMain()
{

  DoubleLinkedListNode *node = new DoubleLinkedListNode(50);

  for(int i = 1;i<10;i++)
  {
    Insert(node, rand () *10 /RAND_MAX);
  }
}
