/*
  treeEx.cpp
  example of what a tree implementation might look like
  Nick Howard Nov 15 2025
*/

#include <iostream>
using namespace std;

struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;
};
typedef struct TreeNode* TreePtr;


void InorderPrint( TreePtr t );
void PreorderPrint( TreePtr t );
void PostorderPrint( TreePtr t );

TreePtr createNode( int data );
void insertNode( TreePtr &t, int val );
bool isLeaf( TreePtr t );




int main() {
  int x;
  TreePtr root = NULL;

  for ( int i = 0; i < 8; i++ ) {
    x = (rand() % 10) + 1;
    cout << "adding: " << x << endl; 
    insertNode( root, x );
  }


  cout << "\nPrinting In Order: " << endl;
  InorderPrint( root );

  cout << "\nPrinting Pre Order: " << endl;
  PreorderPrint( root );

  cout << "\nPrinting Post Order: " << endl;
  PostorderPrint( root );

  if (!isLeaf( root ))
    cout << "root is not leaf" << endl;
  if (isLeaf( root->left->right ))
    cout << "root->left->right is a leaf" << endl;

  return 0;
}


bool isLeaf( TreePtr t ) {
  return (t->left == NULL && t->right == NULL);
}

void InorderPrint( TreePtr t ) {
  if ( t != NULL) {
    InorderPrint( t->left );
    cout << t->data << endl;
    InorderPrint( t->right );
  }
}

void PreorderPrint( TreePtr t ) {
  if ( t != NULL) {
    cout << t->data << endl;
    PreorderPrint( t->left );
    PreorderPrint( t->right );
  }
}

void PostorderPrint( TreePtr t ) {
  if ( t != NULL) {
    PostorderPrint( t->left );
    PostorderPrint( t->right );
    cout << t->data << endl;
  }
}

TreePtr createNode( int data ) {
  TreePtr n = new TreeNode;
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void insertNode( TreePtr &t, int val ) {
  if (t == NULL)
    t = createNode( val ); 
  else if ( val <= t->data )
    insertNode( t->left, val );
  else
    insertNode( t->right, val );
}
