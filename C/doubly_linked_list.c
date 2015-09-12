//========================================================================
// Doubly Linked List
//========================================================================

#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------
// Types: node
//------------------------------------------------------------------------
typedef struct node {
  int data;
  struct node *next;
  struct node *prev;
} node_t;

//------------------------------------------------------------------------
// Interface: *
//------------------------------------------------------------------------
void push(node_t **head_ref, int data);
void insert_after(node_t *prev_node, int data);
void append(node_t **head_ref, int data);
void print_list(node_t *head_node);

//------------------------------------------------------------------------
// Function: push
//------------------------------------------------------------------------
void push(node_t **head_ref, int data) {
  node_t *new_node = (node_t*) malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = (*head_ref);
  new_node->prev = NULL;

  if((*head_ref) != NULL)
    (*head_ref)->prev = new_node;

  (*head_ref) = new_node;
}

//------------------------------------------------------------------------
// Function: insert_after
//------------------------------------------------------------------------
void insert_after(node_t *prev_node, int data) {
  if(prev_node == NULL) {
    printf("Error: can't be NULL!\n");
    return;
  }

  node_t *new_node = (node_t*) malloc(sizeof(node_t));
  new_node->data = data;
  new_node->prev = prev_node;
  new_node->next = prev_node->next;

  if(new_node->next != NULL)
    new_node->next->prev = new_node;
  
}

//------------------------------------------------------------------------
// Function: append
//------------------------------------------------------------------------
void append(node_t **head_ref, int data) {
  node_t *new_node = (node_t*) malloc(sizeof(node_t));
  node_t *last = (*head_ref);

  new_node->data = data;
  new_node->next = NULL;

  if(*head_ref == NULL) {
    new_node->prev = NULL;
    *head_ref = new_node;
    return;
  }

  while(last->next != NULL)
    last = last->next;

  last->next = new_node;
  new_node->prev = last;

  return;
}

//------------------------------------------------------------------------
// Function: print_list
//------------------------------------------------------------------------
void print_list(node_t *head_node) {
  node_t *last_node;

  printf("Traversal in forward direction:\n");
  while(head_node != NULL) {
    printf("%d ", head_node->data);
    last_node = head_node;
    head_node = head_node->next;
  }

  printf("\n");

  printf("Traversal in reverse direction:\n");
  while(last_node != NULL) {
    printf("%d ", last_node->data);
    last_node = last_node->prev;
  }
}

//------------------------------------------------------------------------
// Function: main
//------------------------------------------------------------------------
int main() {
  node_t *head_node = NULL;

  append(&head_node, 6);
  push(&head_node, 7);
  push(&head_node, 1);
  append(&head_node, 4);
  insert_after(head_node->next, 8);

  printf("Content of doubly linked list:\n");
  print_list(head_node);

  return 0;
}
