//========================================================================
// Binary Tree
//========================================================================

#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------
// Types: node_t
//------------------------------------------------------------------------
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

//------------------------------------------------------------------------
// Function: new_node
//------------------------------------------------------------------------
node_t *new_node(int data) {
  node_t *node = (node_t*) malloc(sizeof(node_t));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

//------------------------------------------------------------------------
// Function: main
//------------------------------------------------------------------------
int main() {

  node_t *root = new_node(1);

  root->left = new_node(2);
  root->right = new_node(3);

  root->left->left = new_node(4);
  root->left->right = new_node(5);
  
  return 0;
}
