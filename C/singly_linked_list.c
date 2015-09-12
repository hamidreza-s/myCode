//========================================================================
// Singly Linked List
//========================================================================

#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------
// Types: bool
//------------------------------------------------------------------------
typedef enum bool {
  false = 0,
  true = 1
} bool;

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
void list_print_list(list_node_t *head_node);
void list_insert_after_node(list_node_t *prev_node, int data);
void list_append_node(list_node_t **head_ref, int new_data);
int list_get_count(list_node_t *head_node);
void list_print_count(list_node_t *head_node);
bool list_exist_node(list_node_t *head, int wanted_data);

//------------------------------------------------------------------------
// Function: list_exist_node
//------------------------------------------------------------------------
bool list_exist_node(list_node_t *head, int wanted_data) {
  if(head == NULL)
    return false;

  if(head->data == wanted_data)
    return true;

  return list_exist_node(head->next, wanted_data);
}

//------------------------------------------------------------------------
// Function: list_new_node
//------------------------------------------------------------------------
list_node_t *list_new_node() {
  list_node_t *new_node =
    (list_node_t*) malloc(sizeof(list_node_t));
  return new_node;
}

//------------------------------------------------------------------------
// Function: list_get_count
//------------------------------------------------------------------------
int list_get_count(list_node_t *head_node) {
  int count = 0;
  list_node_t *current_node = head_node;

  if(current_node == NULL)
    return count;

  count++;
  
  while(current_node->next != NULL) {
    count++;
    current_node = current_node->next;
  }

  return count;
}

//------------------------------------------------------------------------
// Function: list_print_count
//------------------------------------------------------------------------
void list_print_count(list_node_t *head_node) {

  int count = list_get_count(head_node);
  printf("Count of nodes is: %d\n", count);

  return;
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
void list_print_list(list_node_t *head_node) {
  if(head_node == NULL) {
    printf("[]\n");
    return;
  }

  printf("[");
  while(head_node != NULL) {
    printf(" %d ", head_node->data);
    head_node = head_node->next;
  }
  printf("]\n");
}

//------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------
int main() {
  list_node_t *head_node = NULL;

  list_print_list(head_node);
  list_print_count(head_node);
  
  list_push_node(&head_node, 7);
  
  list_print_list(head_node);
  list_print_count(head_node);
  
  list_push_node(&head_node, 1);
  
  list_print_list(head_node);
  list_print_count(head_node);
  
  list_push_node(&head_node, 3);
  list_push_node(&head_node, 2);

  list_print_list(head_node);
  list_print_count(head_node);
    
  list_delete_node(&head_node, 1);

  list_print_list(head_node);
  list_print_count(head_node);
  
  list_insert_after_node(head_node->next, 9);

  list_print_list(head_node);
  list_print_count(head_node);

  list_append_node(&head_node, 8);

  list_print_list(head_node);
  list_print_count(head_node);

  printf("Does 5 exist in list: %d\n", list_exist_node(head_node, 5));
  printf("Does 7 exist in list: %d\n", list_exist_node(head_node, 7));
  
  return 0;
}
