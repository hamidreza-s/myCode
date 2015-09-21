//========================================================================
// Stack Linked List
//========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//------------------------------------------------------------------------
// Types: stack_node
//------------------------------------------------------------------------
typedef struct stack_node {
  int data;
  struct stack_node *next;
} stack_node_t;

//------------------------------------------------------------------------
// Function: create_new_node
//------------------------------------------------------------------------
stack_node_t *create_new_node(int data) {
  stack_node_t *new_node = (stack_node_t*) malloc(sizeof(stack_node_t));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

//------------------------------------------------------------------------
// Function: is_empty
//------------------------------------------------------------------------
int is_empty(stack_node_t *root) {
  return !root;
}

//------------------------------------------------------------------------
// Function: push
//------------------------------------------------------------------------
void push(stack_node_t **root, int data) {
  stack_node_t *new_node = create_new_node(data);
  new_node->next = *root;
  *root = new_node;
  printf("%d pushed to stack\n", data);
}

//------------------------------------------------------------------------
// Function: pop
//------------------------------------------------------------------------
int pop(stack_node_t **root) {
  if(is_empty(*root))
    return INT_MIN;

  stack_node_t *temp = *root;
  *root = (*root)->next;
  int popped = temp->data;
  free(temp);

  return popped;
}

//------------------------------------------------------------------------
// Function: peek
//------------------------------------------------------------------------
int peek(stack_node_t *root) {
  if(is_empty(root))
    return INT_MIN;

  return root->data;
}

//------------------------------------------------------------------------
// Function: main
//------------------------------------------------------------------------
int main() {

  stack_node_t *root = NULL;

  push(&root, 10);
  push(&root, 20);
  push(&root, 30);

  printf("%d popped from stack\n", pop(&root));
  printf("Top element is %d\n", peek(root));

  return 0;
  
}
