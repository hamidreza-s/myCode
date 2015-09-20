//========================================================================
// Circular Linked List
//========================================================================

#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------
// Types: node
//------------------------------------------------------------------------
typedef struct node {
  int data;
  struct node *next;
} node_t;

//------------------------------------------------------------------------
// Interfaces: *
//------------------------------------------------------------------------
void push(node_t **head_ref, int data);
void print_list(node_t *head_node);

//------------------------------------------------------------------------
// Function: push
//------------------------------------------------------------------------
void push(node_t **head_ref, int data) {
  node_t *new_node = (node_t*) malloc(sizeof(node_t));
  node_t *temp = *head_ref;
  new_node->data = data;
  new_node->next = (*head_ref);

  if(*head_ref != NULL) {

    while(temp->next != *head_ref) {
      temp = temp->next;
    }
    
    temp->next = new_node;

  } else {

    new_node->next = new_node;
    
  }

  *head_ref = new_node;
}

//------------------------------------------------------------------------
// Function: print_list
//------------------------------------------------------------------------
void print_list(node_t *head_node) {
  node_t *temp = head_node;
  if(head_node != NULL) {
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while (temp != head_node);
  }
  printf("\n");
}

//------------------------------------------------------------------------
// Function: main
//------------------------------------------------------------------------
int main() {
  node_t *head_node = NULL;

  push(&head_node, 12);
  push(&head_node, 56);
  push(&head_node, 2);
  push(&head_node, 11);

  printf("Contents of cicrular linked list:\n");
  print_list(head_node);

  return 0;
}
