//========================================================================
// Binary Search Tree
//========================================================================

#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------
// Types: node_t
//------------------------------------------------------------------------
typedef struct node {
  int key;
  struct node *left, *right;
} node_t;

//------------------------------------------------------------------------
// Function: new_node
//------------------------------------------------------------------------
node_t *new_node(int item) {
  node_t *node = (node_t*) malloc(sizeof(node_t));
  node->key = item;
  node->left = node->right = NULL;
  return node;
}

//------------------------------------------------------------------------
// Function: order_print
//------------------------------------------------------------------------
void order_print(node_t *root) {
  if(root != NULL) {
    order_print(root->left);
    printf("%d ", root->key);
    order_print(root->right);
  }
}

//------------------------------------------------------------------------
// Function: insert
//------------------------------------------------------------------------
node_t *insert(node_t *node, int key) {
  if(node == NULL) return new_node(key);

  if(key < node->key)
    node->left = insert(node->left, key);
  else if(key > node->key)
    node->right = insert(node->right, key);

  return node;
}

//------------------------------------------------------------------------
// Function: main
//------------------------------------------------------------------------
int main() {

  node_t *root = NULL;
  root = insert(root, 50);

  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  order_print(root);
  
  return 0;
}
