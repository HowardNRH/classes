/*
  treeEx.cpp
  example of what a tree implementation might look like
  Nick Howard Nov 14 2025
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




int main() {
  TreePtr root = NULL;

  for ( int i = 0; i < 5; i++ )
    insertNode( root, i );

  InorderPrint( root );
  return 0;
}


void InorderPrint( TreePtr t ) {
  if ( t != NULL) {
    InorderPrint( t->left );
    cout << t->data << endl;
    InorderPrint( t->right );
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
  if (t == NULL) {
    cout << "adding " << val << endl;
    t = createNode( val ); 
  }
  else if ( val <= t->data )
    insertNode( t->left, val );
  else
    insertNode( t->right, val );
}
