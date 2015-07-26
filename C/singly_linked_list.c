//========================================================================
// Singly Linked List
//========================================================================

#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------
// Types: list_node_t
//------------------------------------------------------------------------
typedef struct node {
  int data;
  struct node *next;
} list_node_t;

//------------------------------------------------------------------------
// Interfaces: *
//------------------------------------------------------------------------
list_node_t *list_new_node();
void list_push_node(list_node_t **head_ref, int new_data);
void list_delete_node(list_node_t **head_ref, int data);
void list_print_list(list_node_t *node);
void list_insert_after_node(list_node_t *prev_node, int data);
void list_append_node(list_node_t **head_ref, int new_data);

//------------------------------------------------------------------------
// Function: list_new_node
//------------------------------------------------------------------------
list_node_t *list_new_node() {
  list_node_t *new_node =
    (list_node_t*) malloc(sizeof(list_node_t));
  return new_node;
}

//------------------------------------------------------------------------
// Function: list_push_node
//------------------------------------------------------------------------
void list_push_node(list_node_t **head_ref, int new_data) {
  list_node_t *new_node = list_new_node();
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

//------------------------------------------------------------------------
// Function: list_insert_after_node
//------------------------------------------------------------------------
void list_insert_after_node(list_node_t *prev_node, int new_data) {
  if(prev_node == NULL) {
    puts("previous node cannot be NULL!");
    return;
  }

  list_node_t *new_node = list_new_node();
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

//------------------------------------------------------------------------
// Function: list_append_node
//------------------------------------------------------------------------
void list_append_node(list_node_t **head_ref, int new_data) {
  list_node_t *new_node = list_new_node();
  list_node_t *last = *head_ref;

  new_node->data = new_data;
  new_node->next = NULL;

  if(*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

  while(last->next != NULL)
    last = last->next;

  last->next = new_node;
  return;
}

//------------------------------------------------------------------------
// Function: list_delete_node
//------------------------------------------------------------------------
void list_delete_node(list_node_t **head_ref, int data) {
  list_node_t *tmp = *head_ref;
  list_node_t *prev;

  if(tmp != NULL && tmp->data == data) {
    *head_ref = tmp->next;
    free(tmp);
    return;
  }

  while(tmp != NULL && tmp->data != data) {
    prev = tmp;
    tmp = tmp->next;
  }

  if(tmp == NULL) return;

  prev->next = tmp->next;
  free(tmp);
  return;
}

//------------------------------------------------------------------------
// Function: list_print_list
//------------------------------------------------------------------------
void list_print_list(list_node_t *node) {
  while(node != NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
  puts("");
}

//------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------
int main() {
  list_node_t *head = NULL;

  list_push_node(&head, 7);
  list_push_node(&head, 1);
  list_push_node(&head, 3);
  list_push_node(&head, 2);
  list_print_list(head);
  list_delete_node(&head, 1);
  list_print_list(head);
  list_insert_after_node(head->next, 9);
  list_print_list(head);
  list_append_node(&head, 8);
  list_print_list(head);
  
  return 0;
}
