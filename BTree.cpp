

// C++ program for B-Tree insertion
#include<iostream>
using namespace std;

// A BTree node
class BTreeNode
{
    int                 m_degree;           // Minimum degree (defines the range for number of keys)
    int             *   m_keys;             // An array of keys
    int                 m_currentKeyQty;    // Current number of keys
    BTreeNode       **  m_children;         // An array of child pointers
    bool                m_isLeaf;           // Is true when node is leaf. Otherwise false
public:
    BTreeNode(int degree, bool isLeaf);   // Constructor

                                     // A utility function to insert a new key in the subtree rooted with
                                     // this node. The assumption is, the node must be non-full when this
                                     // function is called
    void insertNonFull(int key);

    // A utility function to split the child y of this node. i is index of y in
    // child array C[].  The Child y must be full when this function is called
    void splitChild(int iOrder, BTreeNode *child);

    // A function to traverse all nodes in a subtree rooted with this node
    void traverse();

    // A function to search a key in subtree rooted with this node.
    BTreeNode *search(int key);   // returns NULL if k is not present.

                                // Make BTree friend of this so that we can access private members of this
                                // class in BTree functions
    friend class BTree;
};

// A BTree
class BTree
{
    BTreeNode * m_root; // Pointer to root node
    int         m_degree;  // Minimum degree
public:
    // Constructor (Initializes tree as empty)
    BTree(int _t)
    {
        m_root      = NULL;
        m_degree    = _t;
    }

    // function to traverse the tree
    void traverse()
    {
        if ( m_root != NULL )
        {
            m_root->traverse();
        }
    }

    // function to search a key in this tree
    BTreeNode* search(int key)
    {
        return (m_root == NULL) ? NULL : m_root->search(key);
    }

    // The main function that inserts a new key in this B-Tree
    void insert(int k);
};

// Constructor for BTreeNode class
BTreeNode::BTreeNode(int degree, bool isLeaf)
{
    // Copy the given minimum degree and leaf property
    m_degree = degree;
    m_isLeaf = isLeaf;

    // Allocate memory for maximum number of possible keys
    // and child pointers
    m_keys      = new int[2 * m_degree - 1];
    m_children  = new BTreeNode *[2 * m_degree];

    // Initialize the number of keys as 0
    m_currentKeyQty = 0;
}

// Function to traverse all nodes in a subtree rooted with this node
void BTreeNode::traverse()
{
    // There are n keys and n+1 children, traverse through n keys
    // and first n children
    int i;
    for ( i = 0; i < m_currentKeyQty; i++ )
    {
        // If this is not leaf, then before printing key[i],
        // traverse the subtree rooted with child C[i].
        if ( m_isLeaf == false )
        {
            m_children[i]->traverse();
        }
        cout << " " << m_keys[i];
    }

    // Print the subtree rooted with last child
    if ( m_isLeaf == false )
    {
        m_children[i]->traverse();
    }
}

// Function to search key k in subtree rooted with this node
BTreeNode *BTreeNode::search(int key)
{
    // Find the first key greater than or equal to k
    int i = 0;
    while ( i < m_currentKeyQty && key > m_keys[i] )
    {
        i++;
    }

    // If the found key is equal to k, return this node
    if ( m_keys[i] == key )
        return this;

    // If key is not found here and this is a leaf node
    if ( m_isLeaf == true )
        return NULL;

    // Go to the appropriate child
    return m_children[i]->search(key);
}

// The main function that inserts a new key in this B-Tree
void BTree::insert(int key)
{
    // If tree is empty
    if ( m_root == NULL )
    {
        // Allocate memory for root
        m_root = new BTreeNode(m_degree, true);
        m_root->m_keys[0] = key;        // Insert key
        m_root->m_currentKeyQty = 1;    // Update number of keys in root
    }
    else // If tree is not empty
    {
        // If root is full, then tree grows in height
        if ( m_root->m_currentKeyQty == 2 * m_degree - 1 )
        {
            // Allocate memory for new root
            BTreeNode *newRoot = new BTreeNode(m_degree, false);

            // Make old root as child of new root
            newRoot->m_children[0] = m_root;

            // Split the old root and move 1 key to the new root
            newRoot->splitChild(0, m_root);

            // New root has two children now.  Decide which of the
            // two children is going to have new key
            int i = 0;
            if ( newRoot->m_keys[0] < key )
            {
                i++;
            }
            newRoot->m_children[i]->insertNonFull(key);

            // Change root
            m_root = newRoot;
        }
        else  // If root is not full, call insertNonFull for root
            m_root->insertNonFull(key);
    }
}

// A utility function to insert a new key in this node
// The assumption is, the node must be non-full when this
// function is called
void BTreeNode::insertNonFull(int key)
{
    // Initialize index as index of rightmost element
    int i = m_currentKeyQty - 1;

    // If this is a leaf node
    if ( m_isLeaf == true )
    {
        // The following loop does two things
        // a) Finds the location of new key to be inserted
        // b) Moves all greater keys to one place ahead
        while ( i >= 0 && m_keys[i] > key )
        {
            m_keys[i + 1] = m_keys[i];
            i--;
        }

        // Insert the new key at found location
        m_keys[i + 1] = key;
        m_currentKeyQty = m_currentKeyQty + 1;
    }
    else // If this node is not leaf
    {
        // Find the child which is going to have the new key
        while ( i >= 0 && m_keys[i] > key )
            i--;

        // See if the found child is full
        if ( m_children[i + 1]->m_currentKeyQty == 2 * m_degree - 1 )
        {
            // If the child is full, then split it
            splitChild(i + 1, m_children[i + 1]);

            // After split, the middle key of C[i] goes up and
            // C[i] is split into two.  See which of the two
            // is going to have the new key
            if ( m_keys[i + 1] < key )
                i++;
        }
        m_children[i + 1]->insertNonFull(key);
    }
}

// A utility function to split the child y of this node
// Note that y must be full when this function is called
void BTreeNode::splitChild(int inOrder, BTreeNode *childNode)
{
    // Create a new node which is going to store (degree-1) keys of childNode:
    BTreeNode *newChild = new BTreeNode(childNode->m_degree, childNode->m_isLeaf);
    newChild->m_currentKeyQty = m_degree - 1;

    // Copy the last (t-1) keys of childNode to newChild
    for ( int j = 0; j < m_degree - 1; j++ )
        newChild->m_keys[j] = childNode->m_keys[j + m_degree];

    // Copy the last degree children of childNode to newChild
    if ( childNode->m_isLeaf == false )
    {
        for ( int j = 0; j < m_degree; j++ )
            newChild->m_children[j] = childNode->m_children[j + m_degree];
    }

    // Reduce the number of keys in childNode:
    childNode->m_currentKeyQty = m_degree - 1;

    // Since this node is going to have a new child,
    // create space of new child
    for ( int j = m_currentKeyQty; j >= inOrder + 1; j-- )
        m_children[j + 1] = m_children[j];

    // Link the new child to this node
    m_children[inOrder + 1] = newChild;

    // A key of y will move to this node. Find location of
    // new key and move all greater keys one space ahead
    for ( int j = m_currentKeyQty - 1; j >= inOrder; j-- )
        m_keys[j + 1] = m_keys[j];

    // Copy the middle key of y to this node
    m_keys[inOrder] = childNode->m_keys[m_degree - 1];

    // Increment count of keys in this node
    m_currentKeyQty = m_currentKeyQty + 1;
}

// Driver program to test above functions
int btreemain()
{
    BTree t(3); // A B-Tree with minimum degree 3
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(8);
    t.insert(9);
    t.insert(4);

    cout << "Traversal of the constructed tree is ";
    t.traverse();

    int k = 6;
    (t.search(k) != NULL) ? cout << "\nPresent" : cout << "\nNot Present";

    k = 15;
    (t.search(k) != NULL) ? cout << "\nPresent" : cout << "\nNot Present";

    return 0;
}